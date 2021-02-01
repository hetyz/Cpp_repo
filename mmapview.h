#ifndef MMAPVIEW_H
#define MMAPVIEW_H
#include <list>
#include <functional> 
#include <map>
#include <algorithm> 

template < class Key, class Value >
class multimap_view
{
    std::list<std::map<Key, Value>* > multimaps; 
public:
    void add( std::map<Key, Value>& d ) 
    {
        multimaps.push_back( &d );
    }

    unsigned int count ( Key k ) const adatszerkezet, adattagok állapotát
        unsigned int counter = 0;
        for( typename std::list<std::map< Key, Value >* >::const_iterator i = multimaps.begin();
                i != multimaps.end(); ++i)
        {
            counter += ( *i )->count( k );
        }
        return counter;
    }

    void remove( std::map<Key, Value>& d )
    {
        multimaps.remove( &d );
    }

	unsigned int erase( Key k )
    {
        unsigned int eraser = 0;
        for( typename std::list<std::map< Key, Value >* >::const_iterator i = multimaps.cbegin();
                i != multimaps.cend(); ++i)
        {
            if((*i)->count( k ) == 1)
            {
                (*i)->erase( k );
                eraser++;
            }
        }
        return eraser;
    }

    template <class Compare>
	operator std::multimap< Key, Value, Compare> const () 
    {
        std::multimap< Key, Value, Compare > mmap;

        for( typename std::list<std::map< Key, Value >* >::const_iterator i = multimaps.cbegin();
                i != multimaps.cend(); ++i)
            {
                for ( typename std::map< Key, Value >::const_iterator it = (*i)->cbegin(); it != (*i)->cend(); it++ )
                {
                    mmap.insert( std::pair< Key, Value > (it->first, it->second) );
                }
            }
        return mmap;
    }
};

#endif // MMAPVIEW_H
