#include "HeroPlane.h"

HeroPlane::HeroPlane() {
  // 加载飞机图片资源
  m_Plane.load(HERO_PATH);

  // 设置发射时间间隔
  m_recoder = 0;

  // 设置坐标
  m_X = GAME_WIDTH * 0.5 - m_Plane.width() * 0.5;
  m_Y = GAME_HEIGHT - m_Plane.height();

  // 设置矩形边框
  m_Rect.setWidth(m_Plane.width());
  m_Rect.setHeight(m_Plane.height());
  m_Rect.moveTo(m_X, m_Y);
}

void HeroPlane::setPosition(int x, int y) {
  m_X = x;
  m_Y = y;
  m_Rect.moveTo(m_X, m_Y);
}

void HeroPlane::shoot() {
  ++m_recoder;  // 累加时间间隔记录变量

  if (m_recoder < BULLET_INTERVAL) {
    return;
  }

  m_recoder = 0;

  for (int i = 0; i < BULLET_NUM; ++i) {
    if (m_bullets[i].m_Free) {
      m_bullets[i].m_Free = false;
      m_bullets[i].m_X = m_X + m_Rect.width() * 0.5 - 10;
      m_bullets[i].m_Y = m_Y - 25;
      break;
    }
  }
}