template <typename T>
class DOC {
public:
	template <typename U>
	string foo(T param_1, U param_2) {
		return "foo(): " + to_string(param_1) + ", " + to_string(param_2);
	}
};
