//
//  PokerManager.cpp
//  Test01
//
//  Created by CoodyChou on 2016/9/21.
//
//

#include "PokerManager.h"
#include <stdio.h>

// for Card
#include "PokerActor.h"

// for Constant
#include "PokerResource.h"

#define D_PokerManager_Shuffle_Count (50)

USING_NS_CC;

#pragma mark - Public
bool PokerManager::init()
{
    if ( CCNode::init() ) 
    {
        this->initialNewCards();
        this->shuffleCards();
        
        return true;
    }
    return false;
}

void PokerManager::initialNewCards()
{
    
    if ( cardArray == NULL ) {
        cardArray = CCArray::create();
    }
    else{
        cardArray->removeAllObjects();
    }
    
    for (int i = 0 ; i <= 52 ; i++) 
    {
        // 產生新的撲克牌（包含鬼牌）
        cardArray->addObject(CCString::createWithFormat("%i", i));
    }
}

void PokerManager::shuffleCards(){
    for (int i = 0 ; i < D_PokerManager_Shuffle_Count ; i++ ) 
    {
        // 0 ~ 52
        unsigned int randomNumberA = arc4random()%(cardArray->count());
        unsigned int randomNumberB = arc4random()%(cardArray->count());
        cardArray->exchangeObjectAtIndex(randomNumberA, randomNumberB);
    }
    
#ifdef D_DEBUG
    // 在 debug 環境下才會列印出牌組
    for ( int i = 0 ; i < cardArray->count() ; i++ ) 
    {
        CCString *value = (CCString *)cardArray->objectAtIndex(i);
        if ( value->intValue() < 10 ) {
            std::cout << " " << value->intValue() << ", " ;
        }
        else{
            std::cout << value->intValue() << ", " ;
        }
        
        if ( i % 5 == 0 ) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
#endif
    
}

// 取得指定數量的 card
cocos2d::CCArray *PokerManager::getCards(unsigned int iCount)
{
    
#ifdef D_Test
    if ( onHandArray == NULL ) {
        onHandArray = CCArray::create();
    }
#endif
    
    if ( iCount > 0 && iCount <= cardArray->count() ) 
    {
        
        CCArray *newCardArray = CCArray::create();
        for ( int i = 0 ; i < iCount ; i++ ) 
        {
            
            CCString *cardNumberString = (CCString *)cardArray->objectAtIndex(0);
            
            PokerActor *card = PokerActor::create();
            card->setPokerNumber(cardNumberString->uintValue());
            card->setPokerCardImage( D_PokerResource_Back , this->getCardPic(cardNumberString->uintValue()));
            newCardArray->addObject(card);
#ifdef D_Test
            onHandArray->addObject(card);
#endif
            cardArray->removeObjectAtIndex(0);
        }
        
        return newCardArray;
    }
    else
    {
        if ( iCount > cardArray->count() ) 
        {
            CCLOG("撲克牌的數量不足，請重新開一副牌以及新局！");
        }
        return NULL;
    }
}

#ifdef D_Test
void PokerManager::flipCards(bool bOpne)
{
    if ( onHandArray != NULL ) {
        for ( int i = 0 ; i < onHandArray->count() ; i++ ) {
            PokerActor *card = (PokerActor *)onHandArray->objectAtIndex(i);
            card->filp(bOpne);
        }
    }
}
#endif

#pragma mark - Private
EnumPokerFlowerColor PokerManager::getFlowerColor(unsigned int uNumber)
{
    return (EnumPokerFlowerColor)(uNumber/13);
}

EnumPokerNumber PokerManager::getNumber(unsigned int uNumber)
{
    return (EnumPokerNumber)((uNumber%13) + 1);
}

const char *PokerManager::getCardPic(unsigned int uNumber)
{
    
    CCString *flowerChar;
    EnumPokerFlowerColor tempPokerFlowerColor = this->getFlowerColor(uNumber);
    switch (tempPokerFlowerColor) 
    {
        case EnumPokerFlowerColor_Clubs:
        {
            //  梅花
            flowerChar = CCString::create("c");
        }
            break;
        case EnumPokerFlowerColor_Diamonds:
        {
            //  方塊
            flowerChar = CCString::create("d");
        }
            break;
        case EnumPokerFlowerColor_Hearts:
        {
            //  紅心
            flowerChar = CCString::create("h");
        }
            break;
        case EnumPokerFlowerColor_Spades:
        {
            //  黑陶
            flowerChar = CCString::create("s");
        }
            break;
        case EnumPokerNumberColor_Ghost:
        {
            //  黑陶
            flowerChar = CCString::create("w");
        }
            break;
        case EnumPokerFlowerColor_NotSet:
        default:
        {
            CCLog(" %d is not set or other error!! Check it!!" , tempPokerFlowerColor );
        }
            break;
    }
    
    CCString *cardPicString = CCString::createWithFormat("pokers_%s%02d.png" , flowerChar->getCString() , this->getNumber(uNumber) );
    return cardPicString->getCString();
}
