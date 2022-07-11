#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

extern void init();
extern int add(int mId, int mGrade, char mGender[7], int mScore);
extern int remove(int mId);
extern int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
				ret = add(id, grade, gender, score);
				cout<<ret<<endl;
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &id, &ans);
				ret = remove(id);
				cout<<ret<<endl;
				if (ans != ret)
					okay = false;
				break;
			case CMD_QUERY: {
				int gradeCnt, genderCnt;
				int gradeArr[3];
				char genderArr[2][7];
				scanf("%d", &gradeCnt);
				if (gradeCnt == 1) {
					scanf("%d %d", &gradeArr[0], &genderCnt);
				} else if (gradeCnt == 2) {
					scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
				} else {
					scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
				}
				if (genderCnt == 1) {
					scanf("%s %d %d", genderArr[0], &score, &ans);
				} else {
					scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
				}
				ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
				cout<<ret<<endl;
				if (ans != ret)
					okay = false;
				break;
			}
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}




////////

#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//점수, id
vector< pair<int, int> > m1;
vector< pair<int, int> > f1;
vector< pair<int, int> > m2;
vector< pair<int, int> > f2;
vector< pair<int, int> > m3;
vector< pair<int, int> > f3;

char MALE[] = "male";
char FEMALE[] = "female";

void init() {
    m1.clear();
    f1.clear();
    m2.clear();
    f2.clear();
    m3.clear();
    f3.clear();
	return;
}

void add(vector< pair<int, int> > &arr, pair<int, int> value){
    int low = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
    arr.insert(arr.begin() + low, value);
    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    
    int topVal = 0;

    if(mGender[0] == 'm'){
        switch(mGrade){
            case 1:
                add(m1, make_pair(mScore, mId));
                topVal = m1.back().second;
                break;
            case 2:
                add(m2, make_pair(mScore, mId));
                topVal = m2.back().second;
                break;
            case 3:
                add(m3, make_pair(mScore, mId));
                topVal = m3.back().second;
                break;
        }

    } else {
        switch(mGrade){
            case 1:
                add(f1, make_pair(mScore, mId));
                topVal = f1.back().second;
                break;
            case 2:
                add(f2, make_pair(mScore, mId));
                topVal = f2.back().second;
                break;
            case 3:
                add(f3, make_pair(mScore, mId));
                topVal = f3.back().second;
                break;
        }

    }
    
	return topVal;
}

int remove(int mId) {
    
    for(int i = 0; i < m1.size(); i++){
        if(m1[i].second == mId){
            m1.erase(m1.begin() + i);
            if(m1.size() == 0) return 0;
            return m1[0].second;
        }
    }

    for(int i = 0; i < m2.size(); i++){
        if(m2[i].second == mId){
            m2.erase(m2.begin() + i);
            if(m2.size() == 0) return 0;
            return m2[0].second;
        }
    }
    for(int i = 0; i < m3.size(); i++){
        if(m3[i].second == mId){
            m3.erase(m3.begin() + i);
            if(m3.size() == 0) return 0;
            return m3[0].second;
        }
    } 

    for(int i = 0; i < f1.size(); i++){
        if(f1[i].second == mId){
            f1.erase(f1.begin() + i);
            if(f1.size() == 0) return 0;
            return f1[0].second;
        }
    } 

    for(int i = 0; i < f2.size(); i++){
        if(f2[i].second == mId){
            f2.erase(f2.begin() + i);
            if(f2.size() == 0) return 0;
            return f2[0].second;
        }
    } 

    for(int i = 0; i < f3.size(); i++){
        if(f3[i].second == mId){
            f3.erase(f3.begin() + i);
            if(f3.size() == 0) return 0;
            return f3[0].second;
        }
    }  

	return 0;
}


int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    
    vector<pair<int, int> > resultList;
    
    int low;

    for(int i = 0; i < mGradeCnt; i++){
        if(mGenderCnt == 2){
            switch(mGrade[i]){
                case 1:
                    low = lower_bound(m1.begin(), m1.end(), make_pair(mScore, 0)) - m1.begin();
                    if(!(low == m1.size())) resultList.push_back(m1[low]);
                    low = lower_bound(f1.begin(), f1.end(), make_pair(mScore, 0)) - f1.begin();
                    if(!(low == f1.size())) resultList.push_back(f1[low]);
                    break;
                case 2:
                    low = lower_bound(m2.begin(), m2.end(), make_pair(mScore, 0)) - m2.begin();
                    if(!(low == m2.size())) resultList.push_back(m2[low]);
                    low = lower_bound(f2.begin(), f2.end(), make_pair(mScore, 0)) - f2.begin();
                    if(!(low == f2.size())) resultList.push_back(f2[low]);
                    break;
                case 3:
                    low = lower_bound(m3.begin(), m3.end(), make_pair(mScore, 0)) - m3.begin();
                    if(!(low == m3.size())) resultList.push_back(m3[low]);
                    low = lower_bound(f3.begin(), f3.end(), make_pair(mScore, 0)) - f3.begin();
                    if(!(low == f3.size())) resultList.push_back(f3[low]);
                    break;
            }
        }else{
            if(mGender[0][0] == 'm'){
                switch(mGrade[i]){
                    case 1:
                        low = lower_bound(m1.begin(), m1.end(), make_pair(mScore, 0)) - m1.begin();
                        if(!(low == m1.size())) resultList.push_back(m1[low]);
                        break;
                    case 2:
                        low = lower_bound(m2.begin(), m2.end(), make_pair(mScore, 0)) - m2.begin();
                        if(!(low == m2.size())) resultList.push_back(m2[low]);
                        break;
                    case 3:
                        low = lower_bound(m3.begin(), m3.end(), make_pair(mScore, 0)) -m3.begin();
                        if(!(low == m3.size())) resultList.push_back(m3[low]);
                        break;
                }
            }else{
                 switch(mGrade[i]){
                    case 1:
                        low = lower_bound(f1.begin(), f1.end(), make_pair(mScore, 0))-f1.begin();
                        if(!(low == f1.size())) resultList.push_back(f1[low]);
                        break;
                    case 2:
                        low = lower_bound(f2.begin(), f2.end(), make_pair(mScore, 0))-f2.begin();
                        if(!(low == f2.size())) resultList.push_back(f2[low]);
                        break;
                    case 3:
                        low = lower_bound(f3.begin(), f3.end(), make_pair(mScore, 0))-f3.begin();
                        if(!(low == f3.size())) resultList.push_back(f3[low]);
                        break;
                }
            }

        }
    }
    if(resultList.size() == 0) return 0;
    sort(resultList.begin(), resultList.end());
    return resultList[0].second;
    
	return 0;
}
