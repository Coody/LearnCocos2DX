//
//  PlayerDataTools.h
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#ifndef PlayerDataTools_h
#define PlayerDataTools_h

#include "cocos2d.h"

class PlayerDataTools : public cocos2d::CCNode{
public:
    static PlayerDataTools *sharedInstance();
    
    void savePlayer(cocos2d::CCString *name , int score );
    
    cocos2d::CCArray *getPlayerDataArray();
    
private:
    virtual bool init();
    
    CREATE_FUNC(PlayerDataTools);
    
    void sequenceData();
    
    cocos2d::CCArray *m_arrLeaderboardDataArray;
    
};

#endif /* PlayerDataTools_h */
