//
//  TitleLabelActor.h
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#ifndef TitleLabelActor_h
#define TitleLabelActor_h

#include "cocos2d.h"

class TitleLabelActor final : public cocos2d::CCLabelTTF{
    
public:
    virtual bool initWithSetting( cocos2d::CCString *titleString , const char *fontName , float fontSize );
    
    static TitleLabelActor *createWithSetting( cocos2d::CCString *titleString , const char *fontName , float fontSize ){
        TitleLabelActor *pRet = new TitleLabelActor();
        if( pRet && pRet->initWithSetting( titleString, fontName, fontSize ) ){
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
        
    }
    
#pragma mark - Actions
    void startHeartBitAction();
    
};

#endif /* TitleLabelActor_h */
