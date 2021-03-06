/*
 * product   : NewsGate - news search WEB server
 * copyright : Copyright (c) 2005-2016 Karen Arutyunov
 * licenses  : CC BY-NC-SA 3.0; see accompanying LICENSE file
 *             Commercial; contact karen.arutyunov@gmail.com
 */

// Copyright (C) 2005-2008 Karen Arutyunov
//
// This program was generated by MySQL Class Generating Compiler
// MySQLClassGen (TM)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

#ifndef _NEWSGATE_EVENT_EVENTRECORD__1784554767_
#define _NEWSGATE_EVENT_EVENTRECORD__1784554767_

#include <limits.h>

#include <string>
#include <sstream>

#include <El/Exception.hpp>
#include <El/MySQL/DB.hpp>

namespace NewsGate
{
  namespace Event
  {
//
// EventRecord class declaration
//
    class EventRecord: public El::MySQL::Row
    {
    public:
      EL_EXCEPTION(Exception, El::MySQL::Exception);
      EL_EXCEPTION(IsNull, Exception);

    public:
      EventRecord(El::MySQL::Result* result, unsigned long use_columns = ULONG_MAX)
        throw(Exception, El::Exception);

      El::MySQL::UnsignedLongLong event_id() const
       throw(Exception, El::Exception);

      El::MySQL::String data() const
       throw(Exception, El::Exception);

    };

//
// EventRecord class definition
//
    inline
    EventRecord::EventRecord(El::MySQL::Result* result, unsigned long use_columns)
      throw(Exception, El::Exception)
        : Row(result)
    {
      unsigned long num_columns = std::min(use_columns, (unsigned long)2);

      if(result->num_fields() != num_columns)
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected number of fields "
             << result->num_fields() << " instead of " << num_columns;

        throw Exception(ostr.str());
      }

      if(use_columns >= 0)
      {
        return;
      }

      enum_field_types type = (*result)[0].type;

      if(type != 8)
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected type " << type
             << " instead of 8 for field event_id";

        throw Exception(ostr.str());
      }

      unsigned int flags = 
        (*result)[0].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x21)
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x21 for field event_id";

        throw Exception(ostr.str());
      }

      const char* name = (*result)[0].name;

      if(strcmp(name, "event_id"))
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected name " << name
             << " instead of event_id for field event_id";

        throw Exception(ostr.str());
      }

      if(use_columns >= 1)
      {
        return;
      }

      type = (*result)[1].type;

      if(type != 252)
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected type " << type
             << " instead of 252 for field data";

        throw Exception(ostr.str());
      }

      flags = 
        (*result)[1].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x81)
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x81 for field data";

        throw Exception(ostr.str());
      }

      name = (*result)[1].name;

      if(strcmp(name, "data"))
      {
        std::ostringstream ostr;
        ostr << "EventRecord::EventRecord: unexpected name " << name
             << " instead of data for field data";

        throw Exception(ostr.str());
      }

    }

    inline
    El::MySQL::UnsignedLongLong
    EventRecord::event_id() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventRecord::event_id: row_ is 0");
      }

      if(0 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventRecord::event_id: unexpected index 0 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      unsigned long long value = 0;
      bool is_null = row_[0] == 0;

      if(!is_null)
      {
        unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
        std::string tmp;
        tmp.assign(row_[0], lengths[0]);

        std::istringstream istr(tmp);
        istr >> value;

        if(istr.fail())
        {
          std::ostringstream ostr;
          ostr << "EventRecord::event_id: failed to convert 'event_id' field data"
            " to unsigned long long";

          throw Exception(ostr.str());
        }
      }

      return El::MySQL::UnsignedLongLong(is_null, value);
    }

    inline
    El::MySQL::String
    EventRecord::data() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventRecord::data: row_ is 0");
      }

      if(1 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventRecord::data: unexpected index 1 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      if(row_[1] == 0)
      {
        El::MySQL::String tmp(true, 0, 0);
        return tmp;
      }

      unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
      El::MySQL::String tmp(false, row_[1], lengths[1]);

      return tmp;
    }

  }
}

namespace NewsGate
{
  namespace Event
  {
//
// EventMessageRecord class declaration
//
    class EventMessageRecord: public El::MySQL::Row
    {
    public:
      EL_EXCEPTION(Exception, El::MySQL::Exception);
      EL_EXCEPTION(IsNull, Exception);

    public:
      EventMessageRecord(El::MySQL::Result* result, unsigned long use_columns = ULONG_MAX)
        throw(Exception, El::Exception);

      El::MySQL::UnsignedLongLong id() const
       throw(Exception, El::Exception);

      El::MySQL::String data() const
       throw(Exception, El::Exception);

    };

//
// EventMessageRecord class definition
//
    inline
    EventMessageRecord::EventMessageRecord(El::MySQL::Result* result, unsigned long use_columns)
      throw(Exception, El::Exception)
        : Row(result)
    {
      unsigned long num_columns = std::min(use_columns, (unsigned long)2);

      if(result->num_fields() != num_columns)
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected number of fields "
             << result->num_fields() << " instead of " << num_columns;

        throw Exception(ostr.str());
      }

      if(use_columns >= 0)
      {
        return;
      }

      enum_field_types type = (*result)[0].type;

      if(type != 8)
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected type " << type
             << " instead of 8 for field id";

        throw Exception(ostr.str());
      }

      unsigned int flags = 
        (*result)[0].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x21)
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x21 for field id";

        throw Exception(ostr.str());
      }

      const char* name = (*result)[0].name;

      if(strcmp(name, "id"))
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected name " << name
             << " instead of id for field id";

        throw Exception(ostr.str());
      }

      if(use_columns >= 1)
      {
        return;
      }

      type = (*result)[1].type;

      if(type != 252)
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected type " << type
             << " instead of 252 for field data";

        throw Exception(ostr.str());
      }

      flags = 
        (*result)[1].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x81)
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x81 for field data";

        throw Exception(ostr.str());
      }

      name = (*result)[1].name;

      if(strcmp(name, "data"))
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::EventMessageRecord: unexpected name " << name
             << " instead of data for field data";

        throw Exception(ostr.str());
      }

    }

    inline
    El::MySQL::UnsignedLongLong
    EventMessageRecord::id() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventMessageRecord::id: row_ is 0");
      }

      if(0 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::id: unexpected index 0 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      unsigned long long value = 0;
      bool is_null = row_[0] == 0;

      if(!is_null)
      {
        unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
        std::string tmp;
        tmp.assign(row_[0], lengths[0]);

        std::istringstream istr(tmp);
        istr >> value;

        if(istr.fail())
        {
          std::ostringstream ostr;
          ostr << "EventMessageRecord::id: failed to convert 'id' field data"
            " to unsigned long long";

          throw Exception(ostr.str());
        }
      }

      return El::MySQL::UnsignedLongLong(is_null, value);
    }

    inline
    El::MySQL::String
    EventMessageRecord::data() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventMessageRecord::data: row_ is 0");
      }

      if(1 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventMessageRecord::data: unexpected index 1 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      if(row_[1] == 0)
      {
        El::MySQL::String tmp(true, 0, 0);
        return tmp;
      }

      unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
      El::MySQL::String tmp(false, row_[1], lengths[1]);

      return tmp;
    }

  }
}

namespace NewsGate
{
  namespace Event
  {
//
// EventLangRecord class declaration
//
    class EventLangRecord: public El::MySQL::Row
    {
    public:
      EL_EXCEPTION(Exception, El::MySQL::Exception);
      EL_EXCEPTION(IsNull, Exception);

    public:
      EventLangRecord(El::MySQL::Result* result, unsigned long use_columns = ULONG_MAX)
        throw(Exception, El::Exception);

      El::MySQL::UnsignedShort lang() const
       throw(Exception, El::Exception);

      El::MySQL::LongLong events() const
       throw(Exception, El::Exception);

    };

//
// EventLangRecord class definition
//
    inline
    EventLangRecord::EventLangRecord(El::MySQL::Result* result, unsigned long use_columns)
      throw(Exception, El::Exception)
        : Row(result)
    {
      unsigned long num_columns = std::min(use_columns, (unsigned long)2);

      if(result->num_fields() != num_columns)
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected number of fields "
             << result->num_fields() << " instead of " << num_columns;

        throw Exception(ostr.str());
      }

      if(use_columns >= 0)
      {
        return;
      }

      enum_field_types type = (*result)[0].type;

      if(type != 2)
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected type " << type
             << " instead of 2 for field lang";

        throw Exception(ostr.str());
      }

      unsigned int flags = 
        (*result)[0].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x21)
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x21 for field lang";

        throw Exception(ostr.str());
      }

      const char* name = (*result)[0].name;

      if(strcmp(name, "lang"))
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected name " << name
             << " instead of lang for field lang";

        throw Exception(ostr.str());
      }

      if(use_columns >= 1)
      {
        return;
      }

      type = (*result)[1].type;

      if(type != 8)
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected type " << type
             << " instead of 8 for field events";

        throw Exception(ostr.str());
      }

      flags = 
        (*result)[1].flags & (UNSIGNED_FLAG|NOT_NULL_FLAG|BINARY_FLAG);

      if(flags != 0x1)
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected flags 0x" << std::hex
             << flags << " instead of 0x1 for field events";

        throw Exception(ostr.str());
      }

      name = (*result)[1].name;

      if(strcmp(name, "events"))
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::EventLangRecord: unexpected name " << name
             << " instead of events for field events";

        throw Exception(ostr.str());
      }

    }

    inline
    El::MySQL::UnsignedShort
    EventLangRecord::lang() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventLangRecord::lang: row_ is 0");
      }

      if(0 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::lang: unexpected index 0 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      unsigned short value = 0;
      bool is_null = row_[0] == 0;

      if(!is_null)
      {
        unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
        std::string tmp;
        tmp.assign(row_[0], lengths[0]);

        std::istringstream istr(tmp);
        istr >> value;

        if(istr.fail())
        {
          std::ostringstream ostr;
          ostr << "EventLangRecord::lang: failed to convert 'lang' field data"
            " to unsigned short";

          throw Exception(ostr.str());
        }
      }

      return El::MySQL::UnsignedShort(is_null, value);
    }

    inline
    El::MySQL::LongLong
    EventLangRecord::events() const
      throw(Exception, El::Exception)
    {
      El::MySQL::DB::init_thread();

      if(row_ == 0)
      {
        throw Exception("EventLangRecord::events: row_ is 0");
      }

      if(1 >= result_->num_fields())
      {
        std::ostringstream ostr;
        ostr << "EventLangRecord::events: unexpected index 1 when number of fileds is "
             << result_->num_fields();

        throw Exception(ostr.str());
      }

      long long value = 0;
      bool is_null = row_[1] == 0;

      if(!is_null)
      {
        unsigned long* lengths = mysql_fetch_lengths(result_->mysql_res());
        std::string tmp;
        tmp.assign(row_[1], lengths[1]);

        std::istringstream istr(tmp);
        istr >> value;

        if(istr.fail())
        {
          std::ostringstream ostr;
          ostr << "EventLangRecord::events: failed to convert 'events' field data"
            " to long long";

          throw Exception(ostr.str());
        }
      }

      return El::MySQL::LongLong(is_null, value);
    }

  }
}

#endif // _NEWSGATE_EVENT_EVENTRECORD__1784554767_
