#pragma once
#include <vector>
#include <ncurses.h>

enum Identifier {
	playerId,
	enemyId,
	projectileId_player,
	projectileId_enemy
};

class DrawableSet {
	public:
		DrawableSet() {
			x = y = speed = 0;
			icon_set.push_back({{' '}});
			hitBoxWidth = hitBoxHeight = 0;
			clock = 0;
		}

		DrawableSet(int x, int y, int speed, std::vector<std::vector<chtype>> icon_set, Identifier identity) {
			this->x = x;
			this->y = y;
			this->speed = speed;
			this->icon_set = icon_set;
			this->identity = identity;
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			clock = 0;
		}

		int getX() {
			return x;
		}

		int getY() {
			return y;
		}
		int getHitBoxWidth() {
			return hitBoxWidth;
		}
		int getHitBoxHeight() {
			return hitBoxHeight;
		}

		int getSpeed() {
			return speed;
		}

		std::vector<std::vector<chtype>> getGraphic() {
			return icon_set;
		}

		bool isInHitbox(int x, int y) {
			if ((x >= this->x && x <= this->x + hitBoxWidth) && (y >= this->y && y <= this->y + hitBoxHeight))
				return true;
			else
				return false;
		}
		bool isInBounds(int boardWidth, int boardHeight) {
			if ((x > 0 && x + hitBoxWidth < boardWidth) && (y > 0 && y + hitBoxHeight < boardHeight))
				return true;
			else
				return false;
		}

		// These 2 methods allow setting a counter for these individual entities
		int getClock() {
			return clock;
		}

		int incrementClock() {
			if ((speed != 0) && (clock + 1) < (1 / speed))
				clock += 1;
			else {
				clock = 0;
				clockAction();
			}
			return clock;
		}
		Identifier getIdentity() {
			return identity;
		}

	protected:
		int x, y;
		double speed;  // 0 to 1
		Identifier identity;
		std::vector<std::vector<chtype>> icon_set;
		int hitBoxWidth, hitBoxHeight;
		int clock;
	private:	
		virtual void clockAction() = 0;
};
