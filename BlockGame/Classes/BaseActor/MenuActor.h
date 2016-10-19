//
//  MenuActor.h
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#ifndef MenuActor_h
#define MenuActor_h

#include "cocos2d.h"

class MenuActor : public cocos2d::CCNode{
    
public:
    
    virtual bool initWithSetting(cocos2d::CCString *titleString,
                                 const char *fontName,
                                 float fontSize,
                                 bool isOpacity,
                                 cocos2d::CCObject *targetObj,
                                 cocos2d::SEL_CallFuncN selPressedResponseBlock);
    
    static MenuActor *createWithSetting(cocos2d::CCString *titleString ,
                                        const char *fontName ,
                                        float fontSize,
                                        bool isOpacity,
                                        cocos2d::CCObject *targetObj ,
                                        cocos2d::SEL_CallFuncN selPressedResponseBlock)
    {
        MenuActor *pRet = new MenuActor();
        if ( pRet && pRet->initWithSetting( titleString, fontName, fontSize , isOpacity , targetObj , selPressedResponseBlock ) ) 
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    /**
     *  移動進入的位置（主要以 X 軸為主，Y 軸由 Manager 來設定）
     *
     *  @return X 軸的位置
     */
    float getMoveInRightToLeftActionStartPosition();
    void startMoveInAction( float delayTime );
    void startMoveOutAction( float delayTime );
    
private:
    
    void selectLevel();
    
    typedef enum{
        EnumMenuActorTag_Menu = 10
    }EnumMenuActorTag;
    
    cocos2d::CCObject *m_targetObj;
    cocos2d::SEL_CallFuncN m_selPressedResponseBlock;
    
};

#endif /* MenuActor_h */
