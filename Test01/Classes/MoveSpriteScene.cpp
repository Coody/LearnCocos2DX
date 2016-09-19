//
//  MoveSpriteScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#include "MoveSpriteScene.h"

USING_NS_CC;

#define D_MoveSpriteLayer_WhiteColor cocos2d::ccc4(255, 255, 255, 255)
#define D_MoveSpriteLayer_Label_Font "Noto Sans CJK TC"

typedef enum{
    EnumMoveSpriteLayerZPosition_TitleLabel = 1,
    EnumMoveSpriteLayerZPosition_Menu = 2,
    EnumMoveSpriteLayerZPosition_StaticSprite = 100,
    EnumMoveSpriteLayerZPosition_MoveSprite = 200
}EnumMoveSpriteLayerZPosition;

CCScene *MoveSpriteLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    MoveSpriteLayer *moveSpriteLayer = MoveSpriteLayer::create();
    
    scene->addChild(moveSpriteLayer);
    
    return scene;
}

bool MoveSpriteLayer::init()
{
    if ( !CCLayerColor::initWithColor(D_MoveSpriteLayer_WhiteColor)) {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // 加入 title
    titleLabel = CCLabelTTF::create( "Move CCSprite Test" , D_MoveSpriteLayer_Label_Font , 60 );
    titleLabel->setColor(ccc3(240, 117, 34));
    titleLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
                                origin.y + visibleSize.height - 100 - titleLabel->getDimensions().height));
    
    this->addChild(titleLabel , EnumMoveSpriteLayerZPosition_TitleLabel);
    
    // 加入 MenuItem
    CCLabelTTF *createLabel = CCLabelTTF::create( "add Sprite", D_MoveSpriteLayer_Label_Font , 36 );
    createLabel->setColor(ccc3(0,0,0));
    CCMenuItemLabel *menuItemLabel = CCMenuItemLabel::create(createLabel,
                                                             this,
                                                             menu_selector(MoveSpriteLayer::createSprite));
    menuItemLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
                                   origin.y + visibleSize.height*0.5));
    
    createSpriteMenu = CCMenu::create(menuItemLabel , NULL);
    createSpriteMenu->setPosition(CCPointZero);
    this->addChild(createSpriteMenu , 2);
    
    // 初始化一些 properties
    spriteArray = CCArray::create();
    spriteArray->retain();
    
    this->createAnimationTexture();
    
    this->setTouchEnabled( true );
    
    return true;
}

void MoveSpriteLayer::createAnimationTexture()
{
    
    // 建立 animation 的 Texture
    cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("s1.plist" , "s1.png");
    frameArray = CCArray::create();
    for ( int i = 1 ; i <= 25 ; i++ )
    {
        CCString *frameName = CCString::createWithFormat( "s1_%04d.png" , i );
        CCSpriteFrame *spriteFrame = cache->spriteFrameByName( frameName->getCString() );
        frameArray->addObject(spriteFrame);
    }
    
    float delayTime = 0.08f;
    treeAnimation = CCAnimation::create();
    treeAnimation->retain();
    treeAnimation->initWithSpriteFrames(frameArray , delayTime);
}

void MoveSpriteLayer::createSprite(CCObject *pSender){

    
    if ( spriteArray->count() < 5 ) {
        // 在左上角的其他地方生成 CCSprite 的位置
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        int position = arc4random() % 3;
        int x = arc4random() % (int)(visibleSize.width*0.5);
        int y = arc4random() % (int)(visibleSize.height*0.5);
        switch (position) {
            case 1:
            {
                x = x + visibleSize.width*0.5;
            }
                break;
            case 2:
            {
                x = x + visibleSize.width*0.5;
                y = y + visibleSize.height*0.5;
            }
                break;
            case 0:
            default:
                // 不改變
                break;
        }
        
        CCSprite *sprite = CCSprite::createWithSpriteFrameName( "s1_0001.png" );
        sprite->setPosition( ccp( x , y ) );
        this->addChild( sprite , EnumMoveSpriteLayerZPosition_StaticSprite);
        
        this->spriteArray->addObject(sprite);
    }
    
}

// Touch 事件
void MoveSpriteLayer::ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){

    CCLOG("test ");
    
    CCTouch *_touch = (CCTouch *)pTouches->anyObject();
    
    CCPoint _location = _touch->getLocation();
    
    CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
    
    for ( int i = 0 ; i < this->spriteArray->count() ; i++ ) {
        CCSprite *tempSprite = (CCSprite *)this->spriteArray->objectAtIndex(i);
        CCRect rect = CCRectMake(tempSprite->getPositionX() - tempSprite->getContentSize().width*0.5,
                                 tempSprite->getPositionY() - tempSprite->getContentSize().height*0.5,
                                 tempSprite->getContentSize().width,
                                 tempSprite->getContentSize().height);
        if ( rect.containsPoint(_trueLocation) ) {
            recentTouchSprite = tempSprite;
            oldPoint = tempSprite->getPosition();
            recentTouchSprite->setZOrder(EnumMoveSpriteLayerZPosition_MoveSprite);
            break;
        }
    }
}

void MoveSpriteLayer::ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    if ( recentTouchSprite != NULL ) {
        
        CCTouch *_touch = (CCTouch *)pTouches->anyObject();
        
        CCPoint _location = _touch->getLocation();
        
        CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
        
        recentTouchSprite->setPosition(ccp(_trueLocation.x, _trueLocation.y));
        
    }
}

void MoveSpriteLayer::ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    if ( recentTouchSprite != NULL ) {
        
        CCTouch *_touch = (CCTouch *)pTouches->anyObject();
        
        CCPoint _location = _touch->getLocation();
        
        CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        
        if ( _trueLocation.x < visibleSize.width*0.5 && _trueLocation.y > visibleSize.height*0.5 ) {
            CCAction *moveAction = CCMoveTo::create(0.15, oldPoint);
            recentTouchSprite->runAction(moveAction);
        }
        recentTouchSprite->setZOrder(EnumMoveSpriteLayerZPosition_StaticSprite);
    }
    recentTouchSprite = NULL;
}

void MoveSpriteLayer::ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    recentTouchSprite = NULL;
}

