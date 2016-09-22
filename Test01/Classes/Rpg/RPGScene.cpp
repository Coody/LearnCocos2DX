//
//  RPGScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/21.
//
//

#include "RPGScene.h"

// for Constant
#include "LearnCocos2DConstant.h"

// for Object
#include "Npc.h"

USING_NS_CC;

CCScene *RPGLayer::scene(){
    
    CCScene *scene = CCScene::create();
    
    RPGLayer *rpgLayer = RPGLayer::create();
    
    scene->addChild(rpgLayer);
    
    return scene;
    
}

bool RPGLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_Layer_WhiteColor) ) {
        
        npcArray = CCArray::create();
        npcArray->retain();
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint point = CCDirector::sharedDirector()->getVisibleOrigin();
        
        CCLabelTTF *label = CCLabelTTF::create( "產生隨機 NPC" , D_Layer_Label_Font , 46);
        label->setColor(D_Layer_BlackColor);
        
        CCMenuItemLabel *menuItemLabel = CCMenuItemLabel::create(label, this, menu_selector(RPGLayer::createNpc));
        menuItemLabel->setPosition( ccp( point.x + visibleSize.width*0.5 , point.y + visibleSize.height*0.5 ));
        
        CCMenu *mainMenu = CCMenu::create( menuItemLabel , NULL );
        mainMenu->setPosition(CCPointZero);
        this->addChild(mainMenu);
        
        CCDelayTime *delayTime = CCDelayTime::create(2.0f);
        CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(RPGLayer::controlNpcMove));
        CCSequence *sequenceAction = CCSequence::createWithTwoActions(delayTime, funcAction);
        CCRepeatForever *repeatAction = CCRepeatForever::create( sequenceAction );
        this->runAction(repeatAction);
        
        return true;
    }
    
    return false;
}

#pragma mark - Private
void RPGLayer::createNpc(){
    
    unsigned int i_RandomNumber = arc4random()%8;
    const char *s_Name = this->getImageName((EnumNpcName)i_RandomNumber);
    
    Npc *npc = Npc::create( s_Name , s_Name );
    npc->setPosition( this->getRandomPoint() );
    this->addChild(npc);
//    if( npcArray == NULL ){
//        npcArray = CCArray::create();
//    }
    npcArray->addObject(npc);
    
}

void RPGLayer::controlNpcMove(){
    if ( npcArray && npcArray->count() > 0 ) {
        unsigned int selectNpcNumber = arc4random()%npcArray->count();
        Npc *npc = (Npc *)npcArray->objectAtIndex(selectNpcNumber);
        npc->goToPoint(this->getRandomPoint());
    }
}

CCPoint RPGLayer::getRandomPoint(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    int width = visibleSize.width;
    int height = visibleSize.height;
    CCPoint randomPoint = CCPointMake((arc4random() % width - 80) + 40  ,
                                      (arc4random() % height - 80) + 40);
#ifdef D_DEBUG
    CCLOG( " Random: (%.0f , %.0f)" , randomPoint.x , randomPoint.y );
#endif
    
    return randomPoint;
    
}

const char *RPGLayer::getImageName( EnumNpcName enumNpcName ){
    switch ( enumNpcName ) {
        case EnumNpcName_haku:
            return D_Animation_Name_Haku;
            break;
        case EnumNpcName_kaito:
            return D_Animation_Name_Kaito;
            break;
        case EnumNpcName_len:
            return D_Animation_Name_Len;
            break;
        case EnumNpcName_luka:
            return D_Animation_Name_Luka;
            break;
        case EnumNpcName_meiko:
            return D_Animation_Name_Meiko;
            break;
        case EnumNpcName_miku:
            return D_Animation_Name_Miku;
            break;
        case EnumNpcName_rin:
            return D_Animation_Name_Rin;
            break;
        case EnumNpcName_teto:
            return D_Animation_Name_Teto;
            break;
        default:
            return "";
            break;
    }
    return "";
}
