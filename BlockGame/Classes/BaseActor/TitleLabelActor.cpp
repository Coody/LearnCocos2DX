//
//  TitleLabelActor.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#include "TitleLabelActor.h"

// for Constant
#include "BlockGameConstant.h"

// for Tools
#include "ActionTools.h"

USING_NS_CC;

bool TitleLabelActor::initWithSetting(cocos2d::CCString *titleString , const char *fontName , float fontSize , bool isOpacity , bool isScaleZero ){
    
    if ( CCLabelTTF::initWithString(titleString->getCString(),
                                    fontName, 
                                    fontSize) ) 
    {
        this->setColor(ccBLACK);
        if ( isOpacity ) {
            this->setOpacity(0.0f);
        }
        if ( isScaleZero ) {
            this->setScale(0.0f);
        }
        return true;
    }
    
    return false;
}

void TitleLabelActor::startHeartBitAction(){
    CCRepeatForever *repeatForever = CCRepeatForever::create(ActionTools::getHeartBitAnimation());
    this->runAction(repeatForever);
}

void TitleLabelActor::startFadeInAction(cocos2d::CCObject *targetObj,
                                        cocos2d::SEL_CallFunc selResponseBlockDone)
{
    this->runAction(ActionTools::getShowAnimation(targetObj, selResponseBlockDone));
}

void TitleLabelActor::startFadeOutAction(cocos2d::CCObject *targetObj,
                                         cocos2d::SEL_CallFunc selResponseBlockDone)
{
    
}

