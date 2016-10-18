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

bool TitleLabelActor::initWithSetting(cocos2d::CCString *titleString , const char *fontName , float fontSize){
    
    if ( CCLabelTTF::initWithString(titleString->getCString(),
                                    fontName, 
                                    fontSize) ) 
    {
        this->setColor(ccBLACK);
        return true;
    }
    
    return false;
}

void TitleLabelActor::startHeartBitAction(){
    CCRepeatForever *repeatForever = CCRepeatForever::create(ActionTools::getHeartBitAnimation());
    this->runAction(repeatForever);
}

