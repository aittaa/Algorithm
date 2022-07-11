#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//점수, id
vector< pair<int, int> > m1(20000);
vector< pair<int, int> > f1(20000);
vector< pair<int, int> > m2(20000);
vector< pair<int, int> > f2(20000);
vector< pair<int, int> > m3(20000);
vector< pair<int, int> > f3(20000);

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

void add(vector< pair<int, int> > arr, pair<int, int> value){
    int low = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
    arr.insert(arr.begin() + low, value);
    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    
    int topVal = 0;

    if(!strcmp(MALE, mGender)){
        switch(mGrade){
            case 1:
                add(m1, make_pair(mScore, mId));
                topVal = m1[m1.size()-1].first;
                break;
            case 2:
                add(m2, make_pair(mScore, mId));
                topVal = m2[m2.size()-1].first;
                break;
            case 3:
                add(m3, make_pair(mScore, mId));
                topVal = m3[m3.size()-1].first;
                break;
        }

    } else {
        switch(mGrade){
            case 1:
                add(f1, make_pair(mScore, mId));
                topVal = f1[f1.size()-1].first;
                break;
            case 2:
                add(f2, make_pair(mScore, mId));
                topVal = f2[f2.size()-1].first;
                break;
            case 3:
                add(f3, make_pair(mScore, mId));
                topVal = f3[f3.size()-1].first;
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
            return m1[0].first;
        }
    }

    for(int i = 0; i < m2.size(); i++){
        if(m2[i].second == mId){
            m2.erase(m2.begin() + i);
            if(m2.size() == 0) return 0;
            return m2[0].first;
        }
    }
    for(int i = 0; i < m3.size(); i++){
        if(m3[i].second == mId){
            m3.erase(m3.begin() + i);
            if(m3.size() == 0) return 0;
            return m3[0].first;
        }
    } 

    for(int i = 0; i < f1.size(); i++){
        if(f1[i].second == mId){
            f1.erase(f1.begin() + i);
            if(f1.size() == 0) return 0;
            return f1[0].first;
        }
    } 

    for(int i = 0; i < f2.size(); i++){
        if(f2[i].second == mId){
            f2.erase(f2.begin() + i);
            if(f2.size() == 0) return 0;
            return f2[0].first;
        }
    } 

    for(int i = 0; i < f3.size(); i++){
        if(f3[i].second == mId){
            f3.erase(f3.begin() + i);
            if(f3.size() == 0) return 0;
            return f3[0].first;
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
                    if(!(low == m1.size()-1)) resultList.push_back(m1[low]);
                    low = lower_bound(f1.begin(), f1.end(), make_pair(mScore, 0)) - f1.begin();
                    if(!(low == f1.size()-1)) resultList.push_back(f1[low]);
                    break;
                case 2:
                    low = lower_bound(m2.begin(), m2.end(), make_pair(mScore, 0)) - m2.begin();
                    if(!(low == m2.size()-1)) resultList.push_back(m2[low]);
                    low = lower_bound(f2.begin(), f2.end(), make_pair(mScore, 0)) - f2.begin();
                    if(!(low == f2.size()-1)) resultList.push_back(f2[low]);
                    break;
                case 3:
                    low = lower_bound(m3.begin(), m3.end(), make_pair(mScore, 0)) - m3.begin();
                    if(!(low == m3.size()-1)) resultList.push_back(m3[low]);
                    low = lower_bound(f3.begin(), f3.end(), make_pair(mScore, 0)) - f3.begin();
                    if(!(low == f3.size()-1)) resultList.push_back(f3[low]);
                    break;
            }
        }else{
            if(!strcmp(MALE, mGender[0])){
                switch(mGrade[i]){
                    case 1:
                        low = lower_bound(m1.begin(), m1.end(), make_pair(mScore, 0)) - m1.begin();
                        if(!(low == m1.size()-1)) resultList.push_back(m1[low]);
                        break;
                    case 2:
                        low = lower_bound(m2.begin(), m2.end(), make_pair(mScore, 0)) - m2.begin();
                        if(!(low == m2.size()-1)) resultList.push_back(m2[low]);
                        break;
                    case 3:
                        low = lower_bound(m3.begin(), m3.end(), make_pair(mScore, 0)) -m3.begin();
                        if(!(low == m3.size()-1)) resultList.push_back(m3[low]);
                        break;
                }
            }else{
                 switch(mGrade[i]){
                    case 1:
                        low = lower_bound(f1.begin(), f1.end(), make_pair(mScore, 0))-f1.begin();
                        if(!(low == f1.size()-1)) resultList.push_back(f1[low]);
                        break;
                    case 2:
                        low = lower_bound(f2.begin(), f2.end(), make_pair(mScore, 0))-f2.begin();
                        if(!(low == f2.size()-1)) resultList.push_back(f2[low]);
                        break;
                    case 3:
                        low = lower_bound(f3.begin(), f3.end(), make_pair(mScore, 0))-f3.begin();
                        if(!(low == f3.size()-1)) resultList.push_back(f3[low]);
                        break;
                }
            }

        }

        if(resultList.size() == 0) return 0;
        sort(resultList.begin(), resultList.end());
        return resultList[0].second;
    }
    
	return 0;
}



