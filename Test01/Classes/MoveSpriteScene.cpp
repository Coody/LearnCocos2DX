//
//  MoveSpriteScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#include "MoveSpriteScene.h"


USING_NS_CC;


CCScene *MoveSpriteLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    MoveSpriteLayer *moveSpriteLayer = MoveSpriteLayer::create();
    
    scene->addChild(moveSpriteLayer);
    
    return scene;
}

bool MoveSpriteLayer::init()
{
    if ( !CCLayerColor::initWithColor(cocos2d::ccc4(255, 255, 255, 255))) {
        return false;
    }
    
    
    return true;
}



