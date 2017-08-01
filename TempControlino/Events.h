#pragma once

template < typename Event >
class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}
protected:
	virtual void OnEvent(const Event &event) = 0;
};

template < typename Event, typename ObserverType_ = Observer< Event > >
class Subject
{
public:
	typedef ObserverType_ ObserverType;
	Subject(){}
	virtual ~Subject(){}
	virtual void attach(ObserverType *observer) = 0;
	virtual void detach(ObserverType *observer) = 0;
};