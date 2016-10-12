//
//  LeaderboardLayer.h
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#ifndef LeaderboardLayer_h
#define LeaderboardLayer_h

#include "cocos2d.h"

typedef enum{
    EnumLeaderboardLayerTag_BackBtn = 10
}EnumLeaderboardLayerTag;


class LeaderboardLayer : public cocos2d::CCLayerColor{
public:
    virtual bool init();
    
    CREATE_FUNC(LeaderboardLayer);
    
    void startLeaderboardAnimation();
    void stopLeaderboardAnimation();
    
    void showLayerAnimation();
    void hideLayerAnimation();
    
    void initialLeaderboard();
    
    void showBackBtnAnimation();
    void hideBackBtnAnimation();
    
    
    
private:
    
    void back();
    
};

#endif /* LeaderboardLayer_h */
