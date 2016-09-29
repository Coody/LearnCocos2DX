//
//  NumbersScene.cpp
//  Test01
//
//  Created by CoodyChou on 2016/9/23.
//
//

#include "NumbersScene.h"

// for Cosntant
#include "LearnCocos2DConstant.h"

// for Class
#include "NumberManager.h"
#include "JPNumberManager.h"
USING_NS_CC;

typedef enum{
    EnumNumberSceneTag_NumberManager = 10,
    EnumNumberSceneTag_JPNumberManager = 20
}EnumNumberSceneTag;

CCScene *NumbersLayer::scene(){
    
    CCScene *scene = CCScene::create();
    
    NumbersLayer *numbersLayer = NumbersLayer::create();
    
    // 設定數字範圍
    numbersLayer->setRandomNumber(100, 200);
    
    scene->addChild(numbersLayer);
    
    return scene;
    
}

bool NumbersLayer::init(){
    
    if ( CCLayerColor::initWithColor(cocos2d::ccc4(0, 0, 0, 255)) ) {
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint visiblePoint = CCDirector::sharedDirector()->getVisibleOrigin();
        
        m_USartRandomNumber = 0;
        m_UEndRandomNumber = 999;
        m_UTapCount = 0;
        m_fSpeed = 1.0f;
        
        JPNumberManager *jpManager = JPNumberManager::create();
        jpManager->setPosition(ccp( visiblePoint.x + visibleSize.width*0.5 ,
                                    visiblePoint.y + visibleSize.height*0.5));
        this->addChild(jpManager , EnumNumberSceneTag_JPNumberManager , EnumNumberSceneTag_JPNumberManager );
        
        NumberManager *manager = NumberManager::create( "impact64.fnt" );
        this->addChild(manager , EnumNumberSceneTag_NumberManager , EnumNumberSceneTag_NumberManager);
        
        this->setTouchEnabled( true );
        
        return true;
        
    }
    
    return false;
}

#pragma mark - Public
void NumbersLayer::setRandomNumber( unsigned int startNumber , unsigned int endNumber ){
    if ( startNumber < endNumber + 1 ) {
        m_USartRandomNumber = startNumber;
        m_UEndRandomNumber = endNumber + 1;
    }
    else{
        CCLOG(" 起始數字必須 < 結束數字!!");
    }
}

#pragma mark - Private
// touch 事件
void NumbersLayer::ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent ){
    
    CCTouch *_touch = (CCTouch *)pTouches->anyObject();
    CCPoint _location = _touch->getLocation();
    CCPoint _trueLocation = ccp(_location.x - this->getPositionX(), _location.y - this->getPositionY());
    
    int iRandomNumber = (arc4random()%(m_UEndRandomNumber - m_USartRandomNumber) + m_USartRandomNumber);
    
    NumberManager *manager = (NumberManager *)getChildByTag(EnumNumberSceneTag_NumberManager);
    manager->getJumpNumbers(iRandomNumber , CCPointMake(_trueLocation.x , _trueLocation.y + 80) );
    
    JPNumberManager *jpManager = (JPNumberManager *)getChildByTag(EnumNumberSceneTag_JPNumberManager);
    jpManager->addJPNumber(iRandomNumber);
    jpManager->startRunJPAnimation();
    
    switch ( m_UTapCount ) {
        case 0:
        {
            CCDelayTime *delayTime = CCDelayTime::create(0.7f);
            CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(NumbersLayer::endQuickTap));
            CCSequence *sequenceAction = CCSequence::create(delayTime , funcAction , NULL);
            this->runAction(sequenceAction);
        }
            break;
        case 1:
        default:
        {
            // 變更速度
            m_fSpeed = 1.0f + m_UTapCount;
            jpManager->setAnimationSpeed(m_fSpeed);
            
            CCDelayTime *delayTime = CCDelayTime::create(2.0f);
            CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(NumbersLayer::endQuickTap));
            CCSequence *sequenceAction = CCSequence::create(delayTime , funcAction , NULL);
            this->runAction(sequenceAction);
        }
            break;
    }
    m_UTapCount = m_UTapCount + 1;
}

void NumbersLayer::endQuickTap()
{

    if ( m_UTapCount > 0  ) {
        m_UTapCount = m_UTapCount - 1;
        if ( m_fSpeed > 1.0f ) {
            m_fSpeed = m_fSpeed - 1;
            if ( m_fSpeed < 0 ) {
                m_fSpeed = 1;
            }
            JPNumberManager *jpManager = (JPNumberManager *)this->getChildByTag(EnumNumberSceneTag_JPNumberManager);
            jpManager->setAnimationSpeed(m_fSpeed);
        }
    }
    
    
}

