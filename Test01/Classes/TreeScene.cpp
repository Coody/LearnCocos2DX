//
//  TreeScene.cpp
//  Test01
//
//  Created by Coody on 2016/9/14.
//
//

#include "TreeScene.h"

// 這是由 cocos2d 所 define 的 name space
USING_NS_CC;

CCScene *TreeLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    TreeLayer *treeLayer = TreeLayer::create();
    
    scene->addChild(treeLayer);
    
    return scene;
}


bool TreeLayer::init()
{
    if ( !this->CCLayerColor::initWithColor(cocos2d::ccc4(255, 255, 255, 255)) ) {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // 加入 label
    titleLabel = CCLabelTTF::create("Create Tree Here!", "Noto Sans CJK TC", 60);
    titleLabel->setColor(ccc3(240, 117, 34));
    titleLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
                                origin.y + visibleSize.height - 100 - titleLabel->getDimensions().height));
    
    this->addChild(titleLabel, 1);
    
    // 加入按鈕
    CCLabelTTF *createLabel = CCLabelTTF::create("Create!", "Noto Sans CJK TC", 36);
    createLabel->setColor(ccc3(0, 0, 0));
    CCMenuItemLabel *createTreeButton = CCMenuItemLabel::create(createLabel,
                                                                this,
                                                                menu_selector(TreeLayer::menuCreateCallback));
    createTreeButton->setPosition(ccp(origin.x + visibleSize.width*0.5, origin.y + visibleSize.height*0.5));
    mainMenu = CCMenu::create(createTreeButton,NULL);
    mainMenu->setPosition(CCPointZero);
    this->addChild(mainMenu , 2);
       
    // 建立陣列
    treeSpriteArray = CCArray::create();
    treeSpriteArray->retain();
    this->createAnimationTexture();
    
    return true;
}

void TreeLayer::createAnimationTexture()
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

    
    // 建立 Tree Sprite
    // why 這裡一定要
//    CCSprite *tree = CCSprite::createWithSpriteFrameName( "s1_0001.png" );
//    tree->runAction(CCRepeatForever::create(CCAnimate::create(treeAnimation)));
//    tree->setPosition(ccp(250, 200));
//    this->addChild(tree);
//    treeSpriteArray->addObject(tree);
}

void TreeLayer::menuCreateCallback(CCObject *pSender)
{
    
//    CCMessageBox("Create Tree!", "Alert");
    if ( this->treeSpriteArray->count() > 5 ) {
        CCLog("fade out!");
        CCFiniteTimeAction *fadeOutAction = cocos2d::CCFadeOut::create(0.5f);
        CCFiniteTimeAction *removeAction = cocos2d::CCRemoveSelf::create(true);
        CCAction *sequenceAction = cocos2d::CCSequence::create(fadeOutAction, removeAction , NULL);
        mainMenu->runAction(sequenceAction);
    }
    else{
        // 加入樹精靈
        this->createTreeAnimation();
    }
}

void TreeLayer::createTreeAnimation()
{
    // 產生 random position
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    int x = arc4random() % (int)visibleSize.width;
    int y = arc4random() % (int)visibleSize.height;
    
    // 產生新的動畫
    // 建立 Tree Sprite
    CCSprite *tree = CCSprite::createWithSpriteFrameName( "s1_0001.png" );
    tree->runAction(CCRepeatForever::create(CCAnimate::create(treeAnimation)));
    tree->setPosition(ccp(x, y));
    this->addChild(tree);
    
    // why crash?
    // 因為在 CCArray::create() 時，在那個方法內呼叫沒有用到這個就會直接 NULL 掉了。
    treeSpriteArray->addObject(tree);
    
}


