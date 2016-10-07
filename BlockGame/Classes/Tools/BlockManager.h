//
//  BlockManager.h
//  BlockGame
//
//  Created by Coody on 2016/10/6.
//
//

#ifndef BlockManager_h
#define BlockManager_h

#include "cocos2d.h"
#include "BasicBlock.h"

class BlockManager : public cocos2d::CCNode{
    
public:
    virtual bool init();
    
    CREATE_FUNC(BlockManager);
    
    void setBlockCount( unsigned int count );
    
    // 建立 blocks
    void createBlocks();
    
    // 新增、移除 block
    void addNewBlock();
    void removeBlock( BasicBlock *removeBlock );
    void removeTouchBlock( CCObject *object );
    
private:
    
    unsigned int m_uiBlockMaxNumber;
    unsigned int m_uiBlockMaxMoveNumber;
    unsigned int m_uiRecentTargetNumber;// 目前目標的 Number
    cocos2d::CCArray *m_arrBlockArray;
    cocos2d::CCDictionary *m_dicGameBoardHashArray;
    
};

#endif /* BlockManager_h */
