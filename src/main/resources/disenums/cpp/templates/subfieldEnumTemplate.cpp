	/*
	 **  @SUBFIELDNAME implementation **
	 */

	hashMap<int,@SUBFIELDNAME*> @SUBFIELDNAME::enumerations;
	short @SUBFIELDNAME::startBit = @STARTBIT;
	short @SUBFIELDNAME::endBit   = @ENDBIT;

@ENUMSINIT

	@SUBFIELDNAME::@SUBFIELDNAME(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	@SUBFIELDNAME* @SUBFIELDNAME::findEnumeration(int aVal) {
	  @SUBFIELDNAME* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string @SUBFIELDNAME::getDescriptionForValue(int aVal) {
	  @SUBFIELDNAME* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	@SUBFIELDNAME @SUBFIELDNAME::getEnumerationForValue(int aVal) throw(EnumException) {
	  @SUBFIELDNAME* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration @SUBFIELDNAME";
		throw EnumException("@SUBFIELDNAME", aVal, ss.str());
	  }
	};

	bool @SUBFIELDNAME::enumerationForValueExists(int aVal) {
	  @SUBFIELDNAME* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	@SUBFIELDNAME::enumContainer @SUBFIELDNAME::getEnumerations() {
	  return (enumerations);
	};


