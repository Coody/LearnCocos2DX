//
//  PokerGameTableScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#include "PokerGameTableScene.h"

// for define
#include "LearnCocos2DConstant.h"
#include "PokerDefine.h"

// for Poker
#include "PokerActor.h"
#include "PokerManager.h"

USING_NS_CC;

typedef enum{
    EnumPokerGameTableSceneTag_PokerManager = 100,
    EnumPokerGameTableSceneTag_Card = 200
}EnumPokerGameTableSceneTag;

CCScene *PokerGameTableLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    PokerGameTableLayer *pokerGameTableLayer = PokerGameTableLayer::create();
    
    scene->addChild(pokerGameTableLayer);
    
    return scene;
}

bool PokerGameTableLayer::init()
{
    
    if ( CCLayerColor::initWithColor(D_Layer_WhiteColor) ) 
    {
        
        CCSize visible = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint point = CCDirector::sharedDirector()->getVisibleOrigin();
        
        // 產生發排管理員
        PokerManager *pokerManager = PokerManager::create();
        cardArray = pokerManager->getCards(5);
        cardArray->retain();
        
        for ( int i = 0 ; i < cardArray->count() ; i++ ) {
            PokerActor *card = (PokerActor *)cardArray->objectAtIndex(i);
            card->setPosition(ccp(250 + (card->getContentSize().width + 30)*i, 200));
            card->setTag(EnumPokerGameTableSceneTag_Card + i);
            this->addChild(card);
        }
        
        // 加入翻牌按鈕
        CCLabelTTF *label = CCLabelTTF::create("翻牌", D_Layer_Label_Font , 60);
        label->setColor(D_Layer_BlackColor);
        CCMenuItemLabel *menuItem = CCMenuItemLabel::create(label, this, menu_selector(PokerGameTableLayer::flipCard));
        menuItem->setPosition( ccp(point.x + visible.width*0.5 , point.y + visible.height*0.85 ));
        
        CCMenu *mainMenu = CCMenu::create(menuItem , NULL);
        mainMenu->setPosition(CCPointZero);
        this->addChild(mainMenu);
        
        return true;
    }
    return false;
    
}

#pragma mark - Private
void PokerGameTableLayer::flipCard( bool bIsNeedOpen )
{
    
#ifdef D_Test_Sequence
    
    for ( int i = 0  ; i < cardArray->count() ; i++ ) {
        PokerActor *card = (PokerActor *)this->getChildByTag(EnumPokerGameTableSceneTag_Card + i);
        
        CCDelayTime *delayAction = CCDelayTime::create(0.6f * D_Animation_Speed * i );
        CCCallFuncN *funcAction = CCCallFuncN::create(this, callfuncN_selector(PokerGameTableLayer::runFlipCardAction));
        CCSequence *sequenceAction = CCSequence::createWithTwoActions( delayAction , funcAction );
        card->runAction(sequenceAction);
    }
    
#else
    
    for ( int i = 0  ; i < cardArray->count() ; i++ ) {
        PokerActor *card = (PokerActor *)this->getChildByTag(EnumPokerGameTableSceneTag_Card + i);
        card->filp( !card->isOpen() );
    }
    
#endif
    
}

#ifdef D_Test_Sequence
void PokerGameTableLayer::runFlipCardAction(CCNode *sender)
{
    PokerActor *card = (PokerActor *)sender;
    card->filp( !card->isOpen() );
}
#endif

void PokerGameTableLayer::changeCard( unsigned int uCount)
{
//    if ( cardArray != NULL ) {
//        for ( int i = 0 ; i < cardArray->count() ; i++ ) {
//            
//        }
//        cardArray->removeAllObjects();
//    }
}

