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

#include "record.h"

using namespace std;

namespace geoarrow {

	void record::set_value(pair<string, string>& named_value)
	{
		_attributes[named_value.first] = named_value.second;
	}

	string record::get_value(string& name) const
	{
		return _attributes.at(name);
	}

	set<string> record::names() const
	{
		set<string> names;
		for (auto const& entry : _attributes)
		{
			names.insert(entry.first);
		}
		return names;
	}
}