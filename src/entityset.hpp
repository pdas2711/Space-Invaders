#pragma once
#include <vector>
#include "drawableset.hpp"
#include "board.hpp"

class EntitySet {
	public:
		EntitySet() {}

		void addEntity(DrawableSet* entity) {
			all_entities.push_back(entity);
		}

		std::vector<DrawableSet*>* getAllEntities() {
			return &all_entities;
		}

		int getSize() {
			return all_entities.size();
		}
	
	private:
		std::vector<DrawableSet*> all_entities;
};
