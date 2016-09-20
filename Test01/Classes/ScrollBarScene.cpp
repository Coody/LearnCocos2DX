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

#define D_ScrollBar_Tag (900)
#define D_ScrollBar_Up_Tag (901)
#define D_ScrollBar_Down_Tag (902)

#pragma mark - ScrollBar 主要 scroll layer
CCScene *ScrollBarLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    ScrollBarLayer *scrollBarLayer = ScrollBarLayer::create();
    
    scene->addChild(scrollBarLayer);
    
    return scene;
}

bool ScrollBarLayer::init()
{
    if ( CCLayer::init() ) {
        
        this->setTouchEnabled( true );
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint point = CCDirector::sharedDirector()->getVisibleOrigin();
        
        // 加入 scrollBar 背景
        CCSprite *scrollBarBackground = CCSprite::create( "selectgame_dragbar_1.png" );
        scrollBarBackground->setAnchorPoint( CCPointMake(0, 0));
        scrollBarBackground->cocos2d::CCNode::setScaleY(visibleSize.width/scrollBarBackground->getContentSize().width);
        scrollBarBackground->setTag(D_ScrollBar_Tag);
        scrollBarBackground->setPosition(ccp( point.x + visibleSize.width - scrollBarBackground->getContentSize().width ,
                                              point.y));
        
        this->addChild(scrollBarBackground , EnumScrollBarLayerZPosition_ScrollBarBG);
        
        // 加入上按鈕
        upButton = CCSprite::create( "but_arrow_1.png" );
        upButton->setAnchorPoint( CCPointMake(0, 0) );
        upButton->setTag(D_ScrollBar_Up_Tag);
        upButton->setPosition( ccp( point.x + visibleSize.width - upButton->getContentSize().width - 2 , point.y + visibleSize.height - upButton->getContentSize().height) );
        this->addChild(upButton , EnumScrollBarLayerZPosition_ScrollBarUp);
        
        // 加上下按鈕
        downButton = CCSprite::create( "but_arrow2_1.png" );
        downButton->setAnchorPoint( CCPointMake(0, 0) );
        downButton->setTag(D_ScrollBar_Up_Tag);
        downButton->setPosition( ccp( point.x + visibleSize.width - downButton->getContentSize().width - 2 , 0 ) );
        this->addChild(downButton , EnumScrollBarLayerZPosition_ScrollBarDown);
        
        // 加入 Scroll Bar
        scrollBar = CCScale9Sprite::create( "but_drag_1.png" );
        scrollBar->setAnchorPoint(CCPointMake(0.5, 0.5));
        scrollBar->setTag(D_ScrollBar_Tag);
        scrollBar->setPosition( ccp( point.x + visibleSize.width - scrollBar->getContentSize().width*0.5 , visibleSize.height - upButton->getContentSize().height - scrollBar->getContentSize().height*0.5 ) );
        this->addChild( scrollBar , EnumScrollBarLayerZPosition_ScrollBar);
        
        scrollMaxDistance = visibleSize.height - upButton->getContentSize().height - downButton->getContentSize().height;
        
        backgroundSprite = CCSprite::create( "scrollBG.png" );
        backgroundSprite->setAnchorPoint( CCPointMake(0, 1) );
        backgroundSprite->setPosition( ccp(0, visibleSize.height) );
        this->addChild(backgroundSprite);
        
        tempBGY = backgroundSprite->getPositionY();
        
        // 建立測試用的簡易 label
        for (int i = 1 ; i <= 15 ; i++) {
            
            CCString *labelString = CCString::createWithFormat("label_%d" , i);
            CCLabelTTF *label = CCLabelTTF::create(labelString->getCString(), D_Layer_Label_Font, 60);
            label->setColor(D_Layer_BlackColor);
            label->setPosition( ccp(150, backgroundSprite->getContentSize().height - 100*i) );
            backgroundSprite->addChild(label , i);
        }
        
        this->setBGMaxDistance(backgroundSprite->getContentSize().height);
        
        return true;
    }
    return false;
}

void ScrollBarLayer::setBGMaxDistance(float tempDistance){
    bgMaxDistance = tempDistance;
    
    // 順便設定 scroll bar 的長度 
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint point = CCDirector::sharedDirector()->getVisibleOrigin();
    float scrollBarRealDistance = ((scrollMaxDistance)/bgMaxDistance)*visibleSize.height;
    scrollBar->setContentSize( CCSizeMake(scrollBar->getContentSize().width, scrollBarRealDistance));
    scrollBar->setPosition( ccp( point.x + visibleSize.width - scrollBar->getContentSize().width*0.5 , visibleSize.height - upButton->getContentSize().height - scrollBar->getContentSize().height*0.5 ) );
    tempBarY = scrollBar->getPositionY();
}



// Touch 事件
void ScrollBarLayer::ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
    CCTouch *_touch = (CCTouch *)pTouches->anyObject();
    
    CCPoint _location = _touch->getLocation();
    
    CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
    
    CCRect rect = CCRectMake(scrollBar->getPositionX() - scrollBar->getContentSize().width*0.5,
                             scrollBar->getPositionY() - scrollBar->getContentSize().height*0.5,
                             scrollBar->getContentSize().width,
                             scrollBar->getContentSize().height);
    if ( rect.containsPoint(_trueLocation) ) {
        // 設定 scrollbar 的距離
        scrollBar->setPosition( ccp(scrollBar->getPositionX(), this->getScrollBarY(_trueLocation.y) ) );
        
        // 設定 sroll 的畫面位置
        backgroundSprite->setPosition( ccp( backgroundSprite->getPositionX() , this->getRealMoveDistance()) );
        recentSprite = scrollBar;
    }

}

void ScrollBarLayer::ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    if ( recentSprite != NULL ) {
        CCTouch *_touch = (CCTouch *)pTouches->anyObject();
        
        CCPoint _location = _touch->getLocation();
        
        CCPoint _trueLocation = ccp(_location.x - this->getPositionX(),
                                    _location.y - this->getPositionY());
        
        recentSprite->setPosition( ccp(recentSprite->getPositionX(), this->getScrollBarY(_trueLocation.y)) );
        // 設定 sroll 的畫面位置
        backgroundSprite->setPosition( ccp( backgroundSprite->getPositionX() , this->getRealMoveDistance() ) );
    }
}

void ScrollBarLayer::ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    if ( recentSprite != NULL ) {
        
    }
    recentSprite = NULL;
}

void ScrollBarLayer::ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    if ( recentSprite != NULL ) {
        
    }
    recentSprite = NULL;
}

// 取得 scroll bar 邊界
double ScrollBarLayer::getScrollBarY(double tempY){
    double newY = tempY;
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    if ( newY + scrollBar->getContentSize().height*0.5 + upButton->getContentSize().height > visibleSize.height ) {
        newY = visibleSize.height - upButton->getContentSize().height - scrollBar->getContentSize().height*0.5;
    }
    else if ( newY - scrollBar->getContentSize().height*0.5 - downButton->getContentSize().height < 0 ) {
        newY = downButton->getContentSize().height + scrollBar->getContentSize().height*0.5;
    }
    return newY;
}

float ScrollBarLayer::getRealMoveDistance(){
    
    float moveDistance = (scrollBar->getPositionY() - tempBarY)*(backgroundSprite->getContentSize().height/scrollBar->getContentSize().height);
    
    return tempBGY + moveDistance*-1;
}
