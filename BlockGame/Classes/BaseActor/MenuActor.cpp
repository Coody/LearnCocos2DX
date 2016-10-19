//
//  MenuActor.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#include "MenuActor.h"

// for Tools
#include "ActionTools.h"

USING_NS_CC;

bool MenuActor::initWithSetting(cocos2d::CCString *titleString,
                                const char *fontName,
                                float fontSize,
                                bool isOpacity,
                                cocos2d::CCObject *targetObj,
                                cocos2d::SEL_CallFuncN selPressedResponseBlock)
{
    if ( CCNode::create() ) {
        
        this->setAnchorPoint(ccp(0.5, 0.5));
        
        CCLabelTTF *labelLow = CCLabelTTF::create(titleString->getCString(),
                                                  fontName,
                                                  fontSize);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(MenuActor::selectLevel));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(CCPointZero);
        this->addChild(menu , EnumMenuActorTag_Menu , EnumMenuActorTag_Menu);
        
        m_targetObj = targetObj;
        m_selPressedResponseBlock = selPressedResponseBlock;
        
        if ( isOpacity ) {
            menu->setOpacity(0.0f);
        }
        
        return true;
    }
    
    return false;
}

float MenuActor::getMoveInRightToLeftActionStartPosition(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    return visibleSize.width*0.9;
}

void MenuActor::startMoveInAction( float delayTime ){
    CCMenu *menu = (CCMenu *)this->getChildByTag(EnumMenuActorTag_Menu);
    menu->runAction( ActionTools::getMoveInRightToLeftAnimation( delayTime ) );
}

void MenuActor::startMoveOutAction( float delayTime ){
    CCMenu *menu = (CCMenu *)this->getChildByTag(EnumMenuActorTag_Menu);
    menu->runAction( ActionTools::getMoveOutLeftToRightAnimation( delayTime ) );
}


#pragma mark - Private
void MenuActor::selectLevel(){
    if ( m_targetObj != NULL && m_selPressedResponseBlock != NULL ) {
        (this->m_targetObj->*m_selPressedResponseBlock)( (CCNode *)this );
    }
}

