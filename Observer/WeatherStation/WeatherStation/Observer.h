#pragma once

#include <set>
#include <functional>
#include <map>

/*
��������� ��������� IObserver. ��� ������ ������������� �����,
�������� �������� ����������� �� ���������������� IObservable
���������� ������� �������� ��� ���������,
������������� ����������� � ����� Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
��������� ��������� IObservable. ��������� ����������� � ���������� �� ����������, � �����
������������ �������� ����������� ������������������ ������������.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> * observer) = 0;
};

// ���������� ���������� IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer, int priority) override
	{
		m_observers.emplace(priority, &observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		for (auto it = m_observers.rbegin(); it != m_observers.rend(); ++it)
		{
			if (it->second)
			{
				it->second->Update(data);
			}
		}
	}

	void RemoveObserver(ObserverType * observer) override
	{
		for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == observer)
			{
				m_observers.erase(it);
				break;
			}
		}
	}

protected:
	// ������-���������� ������ ����������� ������ �����, 
	// � ������� ���������� ���������� �� ���������� � �������
	virtual T GetChangedData()const = 0;

private:
	//std::set<ObserverType *> m_observers;
	std::map<int, ObserverType *> m_observers;
};