//
//  EndGameLayer.h
//  BlockGame
//
//  Created by Chou Coody on 2016/10/10.
//
//

#ifndef EndGameLayer_h
#define EndGameLayer_h

#include "cocos2d.h"

typedef enum{
    EnumEndGameLayerTag_Title = 10,
    EnumEndGameLayerTag_TryAgain = 20,
    EnumEndGameLayerTag_Leaderboard = 30,
    EnumEndGameLayerTag_Restart = 40,
    EnumEndGameLayerTag_LeaderboardLayer = 1000
}EnumEndGameLayerTag;

class EndGameLayer : public cocos2d::CCLayerColor{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(EndGameLayer);
    
    void startInitialLayer();
    
    // TODO: 回呼函式
    void setTryAgainBlock(cocos2d::CCObject *targetObj ,
                          cocos2d::SEL_CallFuncN selDisappearDone );
    
    void stopInitialLayer();
    
private:
    void showLayerAnimation();
    void hideLayerAnimation();
    
    void showTitleAnimation();
    void hideTitleAnimation();
    
    void showMenuButtonAnimation();
    void hideMenuButtonAnimation();
    
    void initialMenu();
    
    void pressedTryAgain();
    void pressedLeaderboard();
    void pressedRestart();
    
    void changeSceneToStartMScene();
};

#endif /* EndGameLayer_h */
