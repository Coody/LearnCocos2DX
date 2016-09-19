//
//  ScrollBarScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#include "ScrollBarScene.h"

// for Constant
#include "LearnCocos2DConstant.h"

USING_NS_CC;

CCScene *ScrollBarLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    ScrollBarLayer *scrollBarLayer = ScrollBarLayer::create();
    
    scene->addChild(scrollBarLayer);
    
    return scene;
}

bool ScrollBarLayer::init()
{
    if ( CCLayerColor::initWithColor(D_Layer_WhiteColor) ) {
        
        this->setTouchEnabled( true );
        
        
        
        return true;
    }
    return false;
}





// Touch 事件
void ScrollBarLayer::ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
    CCTouch *_touch = (CCTouch *)pTouches->anyObject();
    
    CCPoint _location = _touch->getLocation();
    
    CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
    
//    for ( int i = 0 ; i < this->spriteArray->count() ; i++ ) {
//        CCSprite *tempSprite = (CCSprite *)this->spriteArray->objectAtIndex(i);
//        CCRect rect = CCRectMake(tempSprite->getPositionX() - tempSprite->getContentSize().width*0.5,
//                                 tempSprite->getPositionY() - tempSprite->getContentSize().height*0.5,
//                                 tempSprite->getContentSize().width,
//                                 tempSprite->getContentSize().height);
//        if ( rect.containsPoint(_trueLocation) ) {
//            recentTouchSprite = tempSprite;
//            oldPoint = tempSprite->getPosition();
//            recentTouchSprite->setZOrder(EnumMoveSpriteLayerZPosition_MoveSprite);
//            break;
//        }
//    }
}

void ScrollBarLayer::ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
}

void ScrollBarLayer::ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
}

void ScrollBarLayer::ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){

}

