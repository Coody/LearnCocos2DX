//
//  LeaderboardData.h
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#ifndef LeaderboardData_h
#define LeaderboardData_h

#include "cocos2d.h"

class LeaderboardData : public cocos2d::CCNode {
    
public:
    virtual bool init();
    CREATE_FUNC(LeaderboardData);
    
    void setNameAndScore( cocos2d::CCString *name , int score );
    
    cocos2d::CCString *getName();
    int getScore();
    
private:
    
    cocos2d::CCString *m_sName;
    int m_iScore;
};

#endif /* LeaderboardData_h */
