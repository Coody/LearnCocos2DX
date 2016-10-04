//
//  OpenGLColckScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/29.
//
//

#include "OpenGLColckScene.h"

// for Constant
#include "LearnCocos2DConstant.h"

// for Object
#include "XSGClock.h"

USING_NS_CC;

bool OpenGLClockLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_Layer_DarkGrayColor)) {
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint visiblePoint = CCDirector::sharedDirector()->getVisibleOrigin();
        
        XSGClock *clock = XSGClock::create();
        clock->setPosition(ccp(visiblePoint.x + visibleSize.width*0.5, visiblePoint.y + visibleSize.height*0.7));
        this->addChild(clock);
        
        return true;
    }
    
    return false;
    
}

CCScene *OpenGLClockLayer::scene(){
    
    CCScene *scene = CCScene::create();

    OpenGLClockLayer *openGLLayer = OpenGLClockLayer::create();
    
    scene->addChild(openGLLayer);
    
    return scene;
}
