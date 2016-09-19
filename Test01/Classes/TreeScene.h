//
//  TreeScene.h
//  Test01
//
//  Created by Coody on 2016/9/14.
//
//

#ifndef TreeScene_h
#define TreeScene_h

#include "cocos2d.h"

class TreeLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    void menuCreateCallback(CCObject *pSender);
    
//    CREATE_FUNC(TreeLayer);
    
    // 底下這裡等於上面的 CREATE_FUNC(__ClassName__);
    static TreeLayer* create()
    {
        TreeLayer *pRet = new TreeLayer();
        if (pRet && pRet->init())
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
private:
    cocos2d::CCLabelTTF *titleLabel;
    cocos2d::CCMenu *mainMenu;
    cocos2d::CCArray *treeSpriteArray;
    cocos2d::CCAnimation *treeAnimation;
    cocos2d::CCSpriteFrameCache *cache;
    cocos2d::CCArray *frameArray;
    
    void createTreeAnimation();
    void createAnimationTexture();
};


#endif /* TreeScene_hpp */
