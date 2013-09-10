#ifndef AXSTRING_HPP
#define AXSTRING_HPP

#include <string>
#include <list>
#include <iostream>

namespace axian {

template <typename Character>
class AXString {
	typedef std::basic_string<Character> stringType;
	typedef std::list<stringType> containerType;
	typedef typename stringType::size_type sizeType;

	AXString(const AXString &str);
	AXString& operator=(const AXString &str);

	public:
		AXString(const stringType &str) {
			if(!str.empty()) {
				data_.push_back(str);
			}
			size_ = str.size();
		}
		AXString() {
			size_ = 0;
		}

		AXString& append(const stringType &str) {
			data_.push_back(str);
			size_ += str.size();

			return *this;
		}

		friend std::ostream& operator<<(std::ostream& output, const AXString<Character>& str) {
			typename std::list<stringType>::const_iterator iter = str.data_.begin();
			for(;
				iter != str.data_.end();
				++iter) {
				output << (*iter);
			}
			return output;
		}

	private:
		containerType data_;
		sizeType size_;
};

}

#endif
