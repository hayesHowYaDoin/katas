# Brainstorm

The goal of this system, at least within the confines of this toy problem, is to develop a model which can flexibly and descriptively 
handle the pricing of various objects. In this document, I will outline the challenges posed by the original problem and attempt to 
coralle them into tangible requirements.

## Questions

For simple cases (no discount or modifiers), all prices can be expressed in standard floating-point format. For the question of whether 
fractional prices should be representable, my understanding is that fractional prices do exist until an amount must be paid. From there, 
they round up to the nearest hundreth. For multiple items, this means first summing their prices and then delivering a rounded version of 
the sum.

Discounts such as "buy one get one free" and "three for a dollar" vary depending on regional differences (based on a quick Google search). 
In every place that I've lived, "buy one get one free" translates to "half off" and you can buy one for half the price. However, I do 
think there are some places/stores where this isn't the case, and the discount only applies if you buy the specified quantity.

At this point, I really don't see a good reason for why costs and prices should be separate things. Per Google, "Cost is typically the 
expense incurred for making a product or service that is sold by a company. Price is the amount a customer is willing to pay for a product 
or service." Including such a descrepency in the domain model does nothing but complicate the design; as such, I will pick "price" to be 
used in my domain model and refrain from using "cost" unless necessary.

As for the questions about whether or not the free item in "buy one get one free" has an associated price, my answer would be that it does. 
The individual item has an associated "unit price". Any modifiers are included in the "total price" to the customer, and are less a part of 
the "item" object as they are an associated transformation applied while calculating the total price.

## Proposed Implementation

The most flexible solution would be to make each item have an associated unit price. Each item can have any number of associated modifier 
functions for things like "buy one get one free" and "three for a dollar". These functions should be provided in a generic format such that 
new ones can be added at any time. These functions would also have names that reflect the real-world terminology, providing a more intuitive 
way to describe the domain.

In software terminology, Item would be a class with members "unitPrice" and "name" (for legibility). A separate map of Items to discount functions will be stored separately. When computing the total cost for a purchase, the sum of their unit costs and the number of that item in the cart will be fed into each, applying any discounts that are relevant. For a more complex solution, it may be necessary to rank the "order of precedence" for each discount; for now, this simple solution should cover most cases, and we will assume the discounts are in-order.