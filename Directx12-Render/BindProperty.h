#pragma once
#include <variant>
#include <string>
#include "BufferView.h"
#include "DescriptorHeapView.h"
struct BindProperty {
	std::string name;
	std::variant<
		BufferView,
		DescriptorHeapView>
		prop;
	BindProperty() {}
	template<typename A, typename B>
	requires(
		std::is_constructible_v<decltype(name), A&&> || std::is_constructible_v<decltype(prop), B&&>)
		BindProperty(
			A&& a,
			B&& b)
		: name(std::forward<A>(a)),
		  prop(std::forward<B>(b)) {}
};