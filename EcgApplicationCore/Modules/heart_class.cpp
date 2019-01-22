#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
#include "armadillo"
#include <iterator>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;


// algorytm na podstawie: https://www.saedsayad.com/decision_tree.htm

// kompilacja programu: g++ -std=c++11 main.cpp -o main -larmadillo
// przykladowe uruchomienia
// Windows: main.exe matrix_mix_all.csv 100_V5.dat
// Linux: ./main matrix_mix_all.csv 100_V5.dat

class DecisionTree {
    public:
    DecisionTree() {}


    // liczenie entropii dla kolumny typ pobudzenia
    long double calculate_enropy_for_type(vector<vector<string>> train_data) {

        double data_number = 0.0;
        map<string, int> frequency;

        for (vector<vector<string>>::iterator it = train_data.begin() + 1; it != train_data.end(); it++) {
            frequency[it[0][7]]++;
            data_number++;
        }

        long double entropy = 0.0;
        for (map<string,int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
            entropy -= (((long double)(it->second/data_number) * (long double)log((long double)it->second/data_number)));
        }
        return entropy;
    }


    // liczenie entropii dla pozostalych kolumn
    long double calculate_entropy_for_columns(vector<vector<string>> train_data, int i) {
        
        double data_number = 0.0;
        map<string, int> frequency;
        map<string,map<string,int>> frequency_for_type;

        for (vector<vector<string>>::iterator it = train_data.begin() + 1; it != train_data.end(); it++) {
            frequency[it[0][i]]++;
            frequency_for_type[it[0][i]][it[0][7]]++;
            data_number++;
        }

        vector<long double> entropies;
        for (map<string,map<string,int>>::iterator it = frequency_for_type.begin(); it != frequency_for_type.end(); it++) {
            long double tmp = 0;
            for (map<string,int>::iterator ptr = it->second.begin(); ptr != it->second.end(); ptr++) {
                tmp -= (((long double)(ptr->second/data_number) * (long double)log((long double)ptr->second/data_number)));
            }
            entropies.push_back(tmp);
        }

        long double entropy = 0;
        int j = 0;

        for (map<string,int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
            long double entropy_tmp = (long double)(it->second/data_number) * entropies[i];
            j++;
            entropy += entropy_tmp;
        }
        return entropy;
    }


    // liczenie przyrostu dla kazdej kolumny
    map<string,long double> calculate_gains(vector<vector<string>> train_data) {

        long double entropy = calculate_enropy_for_type(train_data);
        vector<long double> entropies;
        for (int i = 0; i < 7; i++) {
            entropies.push_back(calculate_entropy_for_columns(train_data, i));
        }
        map<string,long double> gains;
        int i = 0;
        for (long double en : entropies) {
            gains[train_data[0][i]] = entropy - en;
            i++;
        }
        return gains;
    }


    string get_max(map<string,long double> *gains) {
        
        string key;
        long double value = -1;
        for (map<string,long double>::iterator it = gains->begin(); it != gains->end(); it++) {
            long double tmp = it->second;
            if (tmp > value) {
                value = tmp;
                key = it->first;
            }
        }
        gains->erase(key);
        return key;
    }



    vector<vector<string>> update_data(vector<vector<string>> train_data) {

        for (vector<vector<string>>::iterator it = train_data.begin() + 1; it != train_data.end(); it++) {
            for (int i = 0; i < 7; i++) {
                if (i != 4) {
                    it[0][i] = it[0][i].substr(0,5);
                }
            }
        }
        return train_data;
    }

    // funkcja klasyfikujaca sygnal, czyli nasze drzewo decyzyjne
    void classify_signal(vector<vector<string>> train_data, long double values[]) {

        bool classified = false;
        train_data = update_data(train_data);
        map<string,long double> gains = calculate_gains(train_data);
        vector<string> data;


        for (int i = 0; i < 7; i++) {
            if (i != 4) {
                data.push_back(to_string(values[i]).substr(0,5));
            } else {
                data.push_back(to_string(values[i]).substr(0,2));
            }
        }

        vector<int> *rows = NULL;

        while (gains.size() != 0) {

            string max_value = get_max(&gains);
            // szukanie numeru kolumny, dla ktorej przyrost jest najwiekszy
            int i = 0;
            vector<string> first_row = train_data[0];
            for (string s : first_row) {
                if (s == max_value) {
                    break;
                }
                i++;
            }
            // do rows zapisywane sa numery wierszy z danych testowych,
            // ktorych wartosci sa takie same jak sygnalu, ktory klasyfikujemy

            // przypadek poczatkowy
            // zaczynamy od kolumny, ktora ma najwiekszy przyrost
            if (rows == NULL) {
                rows = new vector<int>();
                int j = 1;
                for (vector<vector<string>>::iterator it = train_data.begin() + 1; it != train_data.end(); it++) {
                    if (it[0][i] == data[i]) {
                        rows->push_back(j);
                    }
                    j++;
                }
            }
            // kazdy kolejny przypadek
            // kolumny z coraz mniejszym przyrostem
            // do tmp_rows zapisywane sa numery wierszy z danych testowych,
            // ktorych wartosci sa takie same jak sygnalu, ktory klasyfikujemy,
            // bierzemy pod uwage tylko numery wierszy, ktore zapisalismy juz w rows,
            // czyli takie, dla ktorych poprzednia kolumna miala takie wartosci jak klasyfikowany sygnal
            else {
                vector<int> *tmp_rows = new vector<int>();
                for (int index = 0; index < rows->size(); index++) {
                    if (train_data[rows->at(index)][i] == data[i]) {
                        tmp_rows->push_back(rows->at(index));
                    }
                }
                rows = tmp_rows;
            }
            // nie da sie sklasyfikowac sygnalu,
            // jesli w danych testowych nie ma wartosci, ktora on przyjmuje
            if (rows == NULL) {
                cout << "Signal can't be classified - not enough train data";
                return;
            }
            // sprawdzenie, czy wartosc kolumny typ pobudzenia dla wszystkich zebranych wierszy
            // jest juz taki sam - jesli jest, to sygnal zostal juz zaklasyfikowany
            string type = train_data[rows->at(0)][7];
            bool same = true;
            for (int index = 1; index < rows->size(); index++) {
                if (type != train_data[rows->at(index)][7]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                classified = true;
                cout << "\nSignal was classified as " << type << "\n\n";
                break;
            }
        }
        if (!classified) {
            string type = train_data[rows->at(0)][7];
            bool same = true;
            for (int index = 1; index < rows->size(); index++) {
                if (type != train_data[rows->at(index)][7]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                cout << "\nSignal was classified as " << type << "\n\n";
            } else {
                // w tym przypadku sygnal zostal zaklasyfikowany do kilku roznych typow
                // mozna sprobowac to zmienic poprzez zwiekszenie ilosci cyfr po przecinku
                // zamiana cyfry 5 w obu substr na wieksza
                cout << "\nSingal was classified as few types\n\n";
            }
        }
    }

};

// czytanie danych do trenowania z pliku csv
vector<vector<string>> read_csv(string filename, string delimeter)
{
	ifstream file(filename);
 
	vector<vector<string>> dataList;
 
	string line = "";
	while (getline(file, line))
	{
		vector<string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
		dataList.push_back(vec);
	}
	file.close();
 
	return dataList;
}

// czytanie sygnalu do przetworzenia z pliku .dat do wektora
arma::vec read_signal(string filename) {

    vector<double> result;
    ifstream in(filename, ios::in);
    double number;

    while (in >> number) {
        result.push_back(number);
    }

    in.close();
    arma::vec signal(result);

    return signal;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        cout << "\nWindows - start program with: main.exe train_data.csv input_file.dat";
        cout << "\nLinux - start program with: ./main train_data.csv input_file.dat\n\n";
        return 0;
    }

    // czytanie pliku z danymi do trenowania
    string train_file(argv[1]);
    vector<vector<string>> train_data = read_csv(train_file, ",");

    // czytanie pliku z sygnalem
    string input_file(argv[2]);
    arma::vec signal = read_signal(input_file);

    // tutaj sa przykladowe dane do sprawdzenia poprawnosci algorytmu
    // sa ulozone w kolejnosci kolumn z pliku do trenowania
    // do usuniecia po przetworzeniu sygnalu
    long double data[7] = {0.006, 0.838, 0.838, 0.465, 31, 0.070, 3.891};

    // miejsce na wyznaczenie wartosci dla sygnalu
    // long double data[7];
    // data[0] = wartosc pola qrs
    // itd.
    
    // klasyfikacja
    DecisionTree *dt = new DecisionTree();
    dt->classify_signal(train_data, data);

    return 0;
}
