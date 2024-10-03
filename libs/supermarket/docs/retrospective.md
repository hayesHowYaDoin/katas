# Retrospective

## What Went Well

I very quickly came to a solid, flexible solution to this problem. While it could use some tidying up (such as creating a few wrappers for cleaner discount list generation and potentially splitting the unit price off of item), I feel that making discounts a collection of ordered, generic functions makes this approach capable of tackling anything I could think up. 

## What Went Poorly

While it didn't have to do with this problem specifically, I was quite happy with the speed with which I was able to generate domain types and get through all of the required boilerplate. That being said, one of the common complaints for this style of C++ where everything is a named type is that it's time consuming to implement all of the required operator overloads and template specializations. Doing so definitely made me pressed for time, and caused a non-negligable amount of code bloat, which harmed readability. It's not fun to need to implement my own std::hash, but after doing it once or twice it wasn't terribly difficult to apply for Item.

## Follow-Up Questions

This exercise makes me wonder if there's a nice "newtype" library floating around in boost or elsewhere, or if I could make it a personal project to generate my own mix-in for this functionality. Could specializing std::plus allow me to deduce and automatically generate std::minus, and so forth? Something almost exactly like [this](https://github.com/joboccara/NamedType/tree/master)...