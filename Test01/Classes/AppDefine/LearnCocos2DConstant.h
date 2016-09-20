//
//  LearnCocos2DConstant.h
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#ifndef LearnCocos2DConstant_h
#define LearnCocos2DConstant_h

#define D_Layer_WhiteColor cocos2d::ccc4(255, 255, 255, 255)
#define D_Layer_Label_Font "Noto Sans CJK TC"
#define D_Layer_BlackColor ccc3(0,0,0)

typedef enum{
    EnumMoveSpriteLayerZPosition_TitleLabel = 1,
    EnumMoveSpriteLayerZPosition_Menu = 2,
    EnumMoveSpriteLayerZPosition_StaticSprite = 100,
    EnumMoveSpriteLayerZPosition_MoveSprite = 200
}EnumMoveSpriteLayerZPosition;

typedef enum{
    EnumScrollBarLayerZPosition_ScrollBarBG = 10,
    EnumScrollBarLayerZPosition_ScrollBarUp = 20,
    EnumScrollBarLayerZPosition_ScrollBarDown = EnumScrollBarLayerZPosition_ScrollBarUp,
    EnumScrollBarLayerZPosition_ScrollBar = 50
}EnumScrollBarLayerZPosition;

#endif /* LearnCocos2DConstant_h */
