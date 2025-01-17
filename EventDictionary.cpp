﻿#include "EventDictionary.h"

void EventDictionary::add_event(const char* name, Event* eventToAdd) {
	EventKeyValue* entry = new EventKeyValue();
	entry->key = name;
	entry->value = eventToAdd;
	_eventList.push_back(entry);
}

Event* EventDictionary::get(const char* name) {
	for (int i = 0; i < _eventList.size(); i++) {
		if (_eventList[i]->key == name) return _eventList[i]->value;
	} return 0;
	
}

bool EventDictionary::contains(const char* name) const {
	for (int i = 0; i < _eventList.size(); i++) {
		if (_eventList[i]->key == name) return true;
	} return false;
}

