// Copyright 2019 Jan Tschada
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

#ifndef RECORD_H
#define RECORD_H

#include <map>
#include <set>
#include <string>

namespace geoarrow {

	// \brief A simple record having attributes.
	class record {

	public:
		void set_value(std::pair<std::string, std::string>& named_value);
		std::string get_value(std::string& name) const;
		std::set<std::string> names() const;

	private:
		std::map<std::string, std::string> _attributes;
	};

}

#endif // !RECORD_H