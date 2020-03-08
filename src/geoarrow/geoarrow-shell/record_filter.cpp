// Copyright 2020 Jan Tschada
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "record_filter.h"
#include "record.h"

using namespace std;

namespace geoarrow {

	record_filter::record_filter()
	{}

	record_filter::~record_filter()
	{}



	void attribute_record_filter::add_equals(std::pair<string, string>& restriction)
	{
		_equals[restriction.first] = restriction.second;
	}

	bool attribute_record_filter::filter(record* record)
	{
		if (nullptr == record)
		{
			return false;
		}

		for (auto const& equal : _equals)
		{
			string attribute_name = equal.first;
			string expected_value = equal.second;
			string value = record->get_value(attribute_name);
			if (0 != expected_value.compare(value))
			{
				return false;
			}
		}
		return true;
	}
}