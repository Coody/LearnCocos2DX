//
//  MenuActor.h
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#ifndef MenuActor_h
#define MenuActor_h

#include "cocos2d.h"

class MenuActor : public cocos2d::CCNode{
    
public:
    
    virtual bool initWithSetting( cocos2d::CCString *titleString , const char *fontName , float fontSize );
    
    static MenuActor *createWithSetting( cocos2d::CCString *titleString , const char *fontName , float fontSize ){
        MenuActor *pRet = new MenuActor();
        if ( pRet && pRet->initWithSetting( titleString, fontName, fontSize) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    cocos2d::CCPoint getMoveInActionStartPosition();
    void startMoveInAction();
    void startMoveOutAction();
    
private:
    
};

#endif /* MenuActor_h */
