#include "st_segment_module.h"
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

St_Segment::St_Segment(){
//    signal_raw = Waves::signal_raw;
//    signal_filtered = Waves::signal_raw;
//    waves_points = Waves::waves_points;
//    waves_points.qrs_onset = {56, 350, 644,926,1213,1495 ,1790 ,2023, 2383, 2688, 2977, 3265,3541,3841,4153,4447,4746};
//    waves_points.qrs_end = {85, 392, 670, 954, 1238, 1527, 2017, 2052, 2415, 2714, 3005, 3290, 3567, 3870, 4178, 4473, 4772};
//    waves_points.t_end = {245,545,824, 1102, 1387, 1681, 1900, 2211, 2577, 2873, 3159, 3438, 3729, 4033, 4343, 4636, 4932};
    St_Points.sig = Waves::signal_filtered;
//  St_Points.sig = {-0.04369,-0.06142,-0.067042,-0.062373,-0.054835,-0.050991,-0.052504,-0.057089,-0.061791,-0.064728,-0.064846,-0.061427,-0.05481,-0.047055,-0.040669,-0.036119,-0.031146,-0.023376,-0.014158,-0.0090167,-0.013227,-0.026153,-0.040366,-0.047404,-0.04524,-0.039877,-0.039085,-0.044225,-0.049634,-0.049931,-0.047342,-0.050129,-0.062893,-0.079205,-0.085844,-0.075536,-0.055287,-0.041043,-0.043266,-0.057483,-0.069156,-0.067649,-0.055697,-0.04549,-0.046314,-0.056076,-0.06449,-0.063719,-0.055798,-0.050066,-0.053585,-0.06354,-0.069158,-0.061591,-0.043261,-0.027465,-0.027996,-0.047268,-0.073895,-0.092976,-0.099856,-0.10439,-0.12069,-0.15072,-0.17648,-0.16948,-0.11188,-0.012865,0.094937,0.1796,0.23724,0.29697,0.39275,0.52112,0.62399,0.6208,0.47135,0.21692,-0.03987,-0.20302,-0.24312,-0.20212,-0.14664,-0.117,-0.11311,-0.11638,-0.1156,-0.11231,-0.11013,-0.10759,-0.10249,-0.097984,-0.099531,-0.10636,-0.10975,-0.10186,-0.085503,-0.072687,-0.072927,-0.083783,-0.093562,-0.092935,-0.083702,-0.075551,-0.075311,-0.079925,-0.08026,-0.070996,-0.056678,-0.047675,-0.050029,-0.059605,-0.065943,-0.062429,-0.052472,-0.046007,-0.04971,-0.060101,-0.066702,-0.061994,-0.048536,-0.036665,-0.034776,-0.041834,-0.049221,-0.04969,-0.044041,-0.039152,-0.039971,-0.044133,-0.045147,-0.04029,-0.034342,-0.034936,-0.043992,-0.054578,-0.057032,-0.048564,-0.036509,-0.031292,-0.036163,-0.043812,-0.043895,-0.033856,-0.022157,-0.020203,-0.03102,-0.045845,-0.052161,-0.045345,-0.032775,-0.026779,-0.033601,-0.048406,-0.0606,-0.063337,-0.058571,-0.053783,-0.054714,-0.060773,-0.067029,-0.069737,-0.069968,-0.071932,-0.07807,-0.086106,-0.090989,-0.089855,-0.085305,-0.083066,-0.086462,-0.092984,-0.096528,-0.093377,-0.086024,-0.080958,-0.082464,-0.088324,-0.091523,-0.086552,-0.074364,-0.061213,-0.052556,-0.047683,-0.040803,-0.027512,-0.010366,0.0026255,0.0058666,0.0026168,0.0028606,0.013908,0.032981,0.049633,0.056036,0.054612,0.055045,0.063951,0.077838,0.086773,0.084705,0.075514,0.068943,0.070714,0.077172,0.079215,0.071352,0.057022,0.045519,0.043733,0.050319,0.057372,0.057684,0.051035,0.043658,0.041904,0.045818,0.049146,0.045745,0.036308,0.02805,0.0275,0.033278,0.036882,0.031244,0.018797,0.010166,0.014058,0.02796,0.039384,0.037012,0.021233,0.0034178,-0.004962,-0.0027102,0.001743,0.00025695,-0.00647,-0.010722,-0.0073575,-0.00037335,0.00072858,-0.0088696,-0.023431,-0.031264,-0.025662,-0.011408,-0.00044622,-0.0010786,-0.010573,-0.018378,-0.016322,-0.0062204,0.0023792,0.0016737,-0.0074255,-0.017217,-0.02142,-0.020585,-0.01968,-0.021303,-0.022745,-0.019857,-0.013007,-0.0077953,-0.0096129,-0.018085,-0.026869,-0.029261,-0.023821,-0.015167,-0.0097461,-0.010682,-0.015577,-0.018724,-0.015934,-0.008206,-0.0010162,0.00029901,-0.0045889,-0.01078,-0.012877,-0.010385,-0.0078755,-0.0098033,-0.015024,-0.017318,-0.011683,-0.00013272,0.0090093,0.008232,-0.0022889,-0.014662,-0.020301,-0.017406,-0.011911,-0.010949,-0.015309,-0.01856,-0.013586,-0.00040774,0.013227,0.019124,0.016876,0.013969,0.017819,0.027664,0.035186,0.033256,0.023681,0.015695,0.016695,0.024868,0.031421,0.029713,0.021796,0.015817,0.017375,0.023693,0.026626,0.020829,0.0087819,-0.0019589,-0.0062418,-0.0057824,-0.0066573,-0.01237,-0.019798,-0.022115,-0.015963,-0.0060342,-0.0019211,-0.009788,-0.026264,-0.040612,-0.043715,-0.035866,-0.025808,-0.022257,-0.026001,-0.03004,-0.027672,-0.01986,-0.014322,-0.017105,-0.025597,-0.030483,-0.025424,-0.014431,-0.0089755,-0.017166,-0.035526,-0.052514,-0.060675,-0.065171,-0.078416,-0.10455,-0.12847,-0.12217,-0.065439,0.03563,0.14928,0.23959,0.29319,0.32941,0.38413,0.4768,0.58571,0.65248,0.61642,0.45614,0.20843,-0.05028,-0.24603,-0.34317,-0.35168,-0.30782,-0.24802,-0.19465,-0.15635,-0.13402,-0.12434,-0.12101,-0.11755,-0.11128,-0.10457,-0.10092,-0.099915,-0.097129,-0.089194,-0.078702,-0.072796,-0.076016,-0.084634,-0.088859,-0.08173,-0.066236,-0.053535,-0.052865,-0.062949,-0.072984,-0.072629,-0.061378,-0.048345,-0.043073,-0.046578,-0.051362,-0.049797,-0.041872,-0.034519,-0.033816,-0.038477,-0.041282,-0.036961,-0.028047,-0.022644,-0.026208,-0.035513,-0.041381,-0.037443,-0.026346,-0.017227,-0.017029,-0.024096,-0.030361,-0.029751,-0.023985,-0.020171,-0.023089,-0.029934,-0.033297,-0.02905,-0.021011,-0.017536,-0.023022,-0.032983,-0.03786,-0.032395,-0.021377,-0.015732,-0.02233,-0.037132,-0.048659,-0.048773,-0.040187,-0.033526,-0.036817,-0.047965,-0.057609,-0.05912,-0.055244,-0.054753,-0.062785,-0.075162,-0.082638,-0.080428,-0.073344,-0.07122,-0.07917,-0.092436,-0.10083,-0.098252,-0.088111,-0.079938,-0.080706,-0.089103,-0.097383,-0.098634,-0.09254,-0.08449,-0.079643,-0.07768,-0.073305,-0.061937,-0.045057,-0.029463,-0.020658,-0.016703,-0.0091219,0.0090163,0.035269,0.058614,0.068917,0.066356,0.06152,0.065558,0.079952,0.095943,0.10384,0.10251,0.099578,0.10252,0.11058,0.11587,0.11226,0.10231,0.094926,0.09607,0.10253,0.10513,0.098008,0.084845,0.075436,0.076373,0.084806,0.091166,0.087877,0.076042,0.064073,0.059752,0.063447,0.068369,0.0673,0.059445,0.051011,0.048949,0.053787,0.058696,0.056029,0.045072,0.033444,0.030177,0.037028,0.046547,0.049156,0.042281,0.03242,0.0282,0.031353,0.035403,0.032965,0.02406,0.016227,0.016106,0.021797,0.024414,0.017688,0.0054041,-0.001649,0.0034757,0.016173,0.024052,0.018787,0.0042719,-0.007041,-0.0060138,0.0047999,0.01414,0.01319,0.0035019,-0.0051719,-0.0048506,0.0031787,0.010339,0.0095726,0.0020739,-0.0042979,-0.0032473,0.003557,0.0081304,0.0045398,-0.0046451,-0.010256,-0.0053179,0.0075536,0.017873,0.016918,0.006156,-0.0041902,-0.0051903,0.0022899,0.0089431,0.0071619,-0.00084823,-0.0054542,-0.00019676,0.010798,0.016566,0.010568,-0.0020198,-0.0092198,-0.0039633,0.0087424,0.016756,0.012784,0.0012712,-0.0061639,-0.0022305,0.0090578,0.016591,0.013098,0.0021968,-0.0053402,-0.0022507,0.0082127,0.015879,0.014335,0.0075822,0.0058906,0.014715,0.028171,0.034211,0.027093,0.014336,0.010424,0.022844,0.044088,0.057898,0.054264,0.038486,0.025808,0.026781,0.037607,0.044678,0.038069,0.020976,0.0060906,0.0031325,0.0099266,0.015441,0.010982,-0.0015986,-0.012395,-0.013625,-0.0070915,-0.0019406,-0.0053365,-0.015435,-0.023254,-0.021554,-0.012059,-0.0038289,-0.0046841,-0.013667,-0.022048,-0.02184,-0.013561,-0.0056334,-0.0058907,-0.013711,-0.020849,-0.019873,-0.011987,-0.0061856,-0.010494,-0.024254,-0.039864,-0.052536,-0.067302,-0.093658,-0.13012,-0.1536,-0.12899,-0.036864,0.10454,0.24856,0.35902,0.4436,0.54278,0.67653,0.79966,0.81865,0.66724,0.37467,0.058983,-0.15489,-0.2212,-0.18945,-0.14494,-0.13607,-0.15287,-0.16191,-0.15015,-0.13317,-0.13013,-0.1404,-0.14721,-0.1386,-0.12026,-0.10796,-0.11044,-0.12167,-0.12832,-0.123,-0.11034,-0.10141,-0.10272,-0.11034,-0.11403,-0.10743,-0.094466,-0.085557,-0.08747,-0.096246,-0.10058,-0.092691,-0.076023,-0.062335,-0.060871,-0.069943,-0.078729,-0.077292,-0.065448,-0.052395,-0.047975,-0.053706,-0.061835,-0.063255,-0.056465,-0.048714,-0.048117,-0.054903,-0.060917,-0.058367,-0.048483,-0.040608,-0.042348,-0.05122,-0.057131,-0.053247,-0.04353,-0.038794,-0.045316,-0.057916,-0.064923,-0.059656,-0.047082,-0.038781,-0.042046,-0.053398,-0.06261,-0.062766,-0.056636,-0.053542,-0.060111,-0.073758,-0.08531,-0.087885,-0.083502,-0.080692,-0.085542,-0.09526,-0.10112,-0.097772,-0.089505,-0.086403,-0.09415,-0.10777,-0.11595,-0.1119,-0.099846,-0.090961,-0.09253,-0.10124,-0.10693,-0.10253,-0.0904,-0.079175,-0.074665,-0.074017,-0.06889,-0.053905,-0.031969,-0.011361,0.0022307,0.010867,0.021564,0.038636,0.058712,0.073804,0.079293,0.078952,0.081601,0.092291,0.10671,0.11487,0.11079,0.098853,0.089782,0.09044,0.097352,0.10081,0.095236,0.084961,0.079562,0.083618,0.091541,0.093009,0.083319,0.068392,0.059452,0.062563,0.073116,0.080128,0.07623,0.064074,0.053517,0.052375,0.059316,0.065505,0.063005,0.05216,0.040845,0.036397,0.038489,0.04021,0.035917,0.027419,0.02194,0.023757,0.028905,0.029193,0.021287,0.011057,0.00782,0.014073,0.021817,0.019951,0.0056799,-0.011514,-0.018147,-0.0093465,0.0063992,0.014923,0.0091464,-0.0048241,-0.013935,-0.010254,0.0022177,0.0119,0.010477,5.5415e-05,-0.0095378,-0.010315,-0.0032814,0.0033316,0.0027565,-0.003312,-0.0066579,-0.0014672,0.0088482,0.014158,0.0075652,-0.0071574,-0.018187,-0.016417,-0.0037619,0.0089139,0.012115,0.0061212,-0.00046607,0.00020405,0.0077494,0.014714,0.01456,0.0081439,0.0021441,0.0020242,0.0066757,0.010159,0.0084345,0.0038913,0.0026929,0.0078197,0.015009,0.016354,0.0083128,-0.0038699,-0.010291,-0.0054387,0.0063593,0.014885,0.01362,0.0057719,0.0010645,0.0062572,0.018542,0.028575,0.029618,0.023975,0.020221,0.024008,0.032061,0.035654,0.030248,0.021489,0.02073,0.033696,0.053496,0.065542,0.060557,0.04349,0.0296,0.030593,0.043568,0.053439,0.046966,0.025308,0.003194,-0.0046273,0.0032619,0.01443,0.015211,0.003773,-0.0090843,-0.011718,-0.0037127,0.0042124,0.0016689,-0.010611,-0.021709,-0.02188,-0.012461,-0.0041625,-0.0060774,-0.016709,-0.025863,-0.024804,-0.014776,-0.0054105,-0.0052045,-0.01337,-0.021032,-0.020532,-0.013614,-0.010211,-0.019075,-0.039706,-0.063764,-0.08411,-0.10182,-0.12352,-0.15151,-0.1763,-0.1787,-0.14026,-0.055375,0.062152,0.1839,0.28402,0.36004,0.43824,0.54966,0.68927,0.79598,0.7838,0.6091,0.31757,0.023713,-0.16538,-0.21808,-0.18281,-0.13367,-0.11288,-0.11706,-0.12448,-0.12432,-0.12062,-0.11819,-0.11479,-0.10745,-0.10024,-0.10056,-0.1087,-0.11527,-0.11075,-0.096424,-0.083731,-0.082683,-0.091692,-0.099464,-0.096447,-0.084161,-0.073263,-0.072563,-0.080371,-0.086421,-0.082326,-0.069865,-0.059029,-0.057783,-0.064108,-0.068326,-0.063217,-0.051565,-0.043237,-0.04492,-0.053257,-0.058291,-0.05371,-0.043109,-0.036145,-0.038625,-0.047013,-0.052626,-0.050662,-0.044458,-0.040888,-0.042449,-0.044805};
    St_Gui_Values.offset_Threshold_Min = -0.15;
    St_Gui_Values.offset_Threshold_Max = 0.15;
    St_Gui_Values.type_Detection_Threshold = 0.04;
    St_Gui_Values.segment_Linearity_Min = -0.05;
    St_Gui_Values.segment_Linearity_Max = 0.05;
};

//metoda wyznaczania szczytu załamka T
void St_Segment::find_t_peaks(){

    int signalLength;

    if((int)waves_points.qrs_end.size() < (int)waves_points.t_end.size()){
        signalLength = (int)waves_points.qrs_end.size();
    }else {
        signalLength = (int)waves_points.t_end.size();
    }
    int k = 0, j = 0, i = 0;
    arma::uvec qOn(waves_points.qrs_onset.size());
    arma::uvec qEnd(waves_points.qrs_end.size());
    arma::uvec tEnd(waves_points.t_end.size());
    arma::uvec tPeak(waves_points.t_end.size());
    while(i < signalLength - 1){
        //warunki pilnujące poprawności w doborze punktów
        if(waves_points.qrs_end(i) < waves_points.t_end(j)){
            if(waves_points.qrs_end(i+1) > waves_points.t_end(j)){
                //tworzenie własnej struktury punktów (tylko te które są kompletne, czyli dla zespołu QRS
                //jest wyznaczony Qonset,Qend,Tend)
                qEnd[k]= waves_points.qrs_end(i);
                qOn[k] = waves_points.qrs_onset(i);
                tEnd[k] = waves_points.t_end(j);
                tPeak[k] = qEnd[k] + St_Points.sig.subvec(waves_points.qrs_end(i), waves_points.t_end(j)).index_max();
                k++;
                j++;
            }
        }else{
            j++;
            i--;
        }
        i++;
    }

    arma::uvec qEndResized(k), qOnResized(k), tPeakResized(k);
    //pozbycie się nadmiarowości miejsca w tablicy (bałem się alokować dynamicznie xd)
    for (int y = 0; y < k;y++) {
        qEndResized[y] = qEnd[y];
        qOnResized[y] = qOn[y];
        tPeakResized[y] = tPeak[y];
    }
    St_Points.q_on = qOnResized;
    St_Points.q_end = qEndResized;
    St_Points.t_peak = tPeakResized;
//    for (int y=0;y<tPeakResized.size();y++) {
//           cout<<St_Points.t_peak(y)<<" ";
//   }
}

//metoda wyznaczenia początku załamka T
void St_Segment::find_t_ons(){

    int signalLength = (int)St_Points.t_peak.size();
    double X1, X2, Y1, Y2, a, K, l=0;
    arma::vec lineSegmentDistance(1000);
    lineSegmentDistance.zeros();
    arma::uvec tOn(St_Points.t_peak.size());

    //wyznaczenie prostej miedzy Qend + 20 próbek, a szczytem T, następnie szukanie najdalej oddalonego punktu
    for(int i = 0; i < signalLength; i++){
        X1 = St_Points.q_end(i) + 20;
        X2 = St_Points.t_peak(i);
        Y1 = St_Points.sig(X1);
        Y2 = St_Points.sig(X2);
        a = (Y2-Y1)/(X2-X1);
        K = (Y1*X2 - Y2*X1)/(X2-X1);
        l=0;
        lineSegmentDistance.zeros();
        for (int j = X1; j < X2; j++) {
            lineSegmentDistance(l) = (abs(a*j - St_Points.sig(j) + K))/sqrt(1+a*a);
            l++;
        }
        tOn(i) = lineSegmentDistance.index_max() + X1;
    }
    St_Points.t_on = tOn;
//        cout<<"\n";
//        for (int y=0;y<tOn.size();y++) {
//                cout<<St_Points.t_on(y)<<" ";
//        }
}

//metoda wyznaczająca offset pomiędzy kolejnymi parami punktów Qon, a JX (Qend + 20)
void St_Segment::offsets(){
   int signalLength = (int)St_Points.t_peak.size();
    arma::ivec tOff(St_Points.t_peak.size());
    tOff.zeros();
    int JX;
    double O;
    double offsetMin = St_Gui_Values.offset_Threshold_Min, offsetMax = St_Gui_Values.offset_Threshold_Max;

    //sprawdzanie offsetu miedzy Qon, a JX
    for (int i = 0;i < signalLength; i++) {
        JX = St_Points.q_end(i) + 29;
        O = St_Points.sig(JX) - St_Points.sig(St_Points.q_on(i));

        if (O < offsetMin)
            tOff(i) = -1;       //offset ujemny
        else if (O > offsetMax)
            tOff(i) = 1;        //offset dodatni
        else
            tOff(i)=0;          //offset zerowy
    }
    St_Points.offset = tOff;
//    cout<<"\n";
//    for (int y=0;y<tOff.size();y++) {
//            cout<<St_Points.offset(y)<<" ";
//    }
}

//metoda wyznaczająca rodzaj odcinka S-T
void St_Segment::slopes(){
    // Output (rodzaj zbocza): 0 - płaskie, 1 - opadające, 2 - rosnące, 3 - wklęsłe, 4 - wypukłe
    int signalLength = St_Points.t_peak.size();
    arma::vec lineSegmentDistance(1000);
    lineSegmentDistance.zeros();
    arma::vec curveSegmentDistance(1000);
    curveSegmentDistance.zeros();
    arma::uvec stSegmentType(signalLength);
    stSegmentType.fill(9);
    curveSegmentDistance.zeros();
    double TE, X1, X2, Y1, Y2, a , K, curveSegmentType;
    double stSegmentTypeDetectionThreshold = St_Gui_Values.type_Detection_Threshold;
    double lineSegmentTypeDetectionThresholdMin = St_Gui_Values.segment_Linearity_Min;
    double lineSegmentTypeDetectionThresholdMax = St_Gui_Values.segment_Linearity_Max;
    int l;

    for (int i = 0; i < signalLength; i++) {

        if (St_Points.offset(i) == 1)
            TE = St_Points.t_peak(i);
        else
            TE = St_Points.t_on(i);
        X1 = St_Points.q_end(i)+20;
        X2 = TE;
        Y1 = St_Points.sig(X1);
        Y2 = St_Points.sig(X2);
        a = (Y2-Y1)/(X2-X1);
        K = (Y1*X2 - Y2*X1)/(X2 - X1);
        l = 0;
        for (int j = X1; j < X2; j++) {
            lineSegmentDistance(l) = (abs(a*j - St_Points.sig(j) + K)) / sqrt(1+a*a);
            curveSegmentDistance(l) = (a*j - St_Points.sig(j) + K) / sqrt(1+a*a);
            l++;
        }

        if(lineSegmentDistance.max() > stSegmentTypeDetectionThreshold){
            curveSegmentType = sum(curveSegmentDistance);
            if(curveSegmentType < 0)
                stSegmentType(i) = 5;   //zbocze wypukłe
            else
                stSegmentType(i) = 4;   //zbocze wklęsłe
        }else{
            if(a > lineSegmentTypeDetectionThresholdMax)
                stSegmentType(i) = 3;   //zbocze narastające
            else if (a < lineSegmentTypeDetectionThresholdMin)
                stSegmentType(i) = 2;   //zbocze opadające
            else
                stSegmentType(i) = 1;   //zbocze płaskie
        }
    }
    St_Points.slope = stSegmentType;
//    cout<<"\n";
//    for (int y=0;y<stSegmentType.size();y++) {
//            cout<<St_Points.slope(y)<<" ";
//    }
}

void St_Segment::classify(){
    //Wiersz: 0 - niedokrwienie mięśnia sercowego
    //Wiersz: 1 - niedokrwienie mięśnia sercowego
    //Wiersz: 2 - niedokrwienie mięśnia sercowego
    //Wiersz: 3 - niedokrwienie mięśnia sercowego
    //Wiersz: 4 - cięzki zawał mięśnia sercowego
    //Wiersz: 5 - ostry zawał mięśnia sercowego
    //Wiersz: 6 - brak wykrytych patologii
    int signalLength = St_Points.slope.size();

    arma::ivec stSegementClassified(St_Points.slope.size());
    arma::mat stSegmentClassificationMatrix(signalLength + 1, 7);
    stSegmentClassificationMatrix.zeros();
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1;
    for (int i = 0; i < signalLength; i++) {
        stSegementClassified(i) = St_Points.offset(i) * St_Points.slope(i);
        switch (stSegementClassified(i)) {
        case -1:
            stSegmentClassificationMatrix(a,0) = i;
            a++;
            break;
        case -2:
            stSegmentClassificationMatrix(b,1) = i;
            b++;
            break;
        case -4:
            stSegmentClassificationMatrix(c,2) = i;
            c++;
            break;
        case 4:
            stSegmentClassificationMatrix(d,3) = i;
            d++;
            break;
        case -5:
            stSegmentClassificationMatrix(e,4) = i;
            e++;
            break;
        case 5:
            stSegmentClassificationMatrix(f,5) = i;
            f++;
            break;
        default:
            stSegmentClassificationMatrix(g,6) = i;
            g++;
            break;
        }
    }
    //cout<<"xd";

    stSegmentClassificationMatrix(0,0) = a - 1;
    stSegmentClassificationMatrix(0,1) = b - 1;
    stSegmentClassificationMatrix(0,2) = c - 1;
    stSegmentClassificationMatrix(0,3) = d - 1;
    stSegmentClassificationMatrix(0,4) = e - 1;
    stSegmentClassificationMatrix(0,5) = f - 1;
    stSegmentClassificationMatrix(0,6) = g - 1;
    St_Points.diagnose = stSegmentClassificationMatrix;
//    cout<<"\n";
//    for(int i = 0; i < St_Points.diagnose.n_cols; i++){
//        for(int j = 0; j < St_Points.diagnose.n_rows; j++){
//            cout<<St_Points.diagnose(j,i)<<" ";
//        }
//        cout<<"\n";
//    }
}

void St_Segment::analyze(){
    find_t_peaks();
    find_t_ons();
    offsets();
    slopes();
    classify();
}

void St_Segment::set_St_Params(double offsetmin, double offsetmax, double detectionthreshold, double linearitymin, double linearitymax){
        St_Gui_Values.offset_Threshold_Min = offsetmin;
        St_Gui_Values.offset_Threshold_Max = offsetmax;
        St_Gui_Values.type_Detection_Threshold = detectionthreshold;
        St_Gui_Values.segment_Linearity_Min = linearitymin;
        St_Gui_Values.segment_Linearity_Max = linearitymax;
}

// Developed by Filip 'Benitto' Jamróz
