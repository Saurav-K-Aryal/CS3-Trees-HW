# Computer Science III - Data Structures Class

Contributors:
- Anurrag Rijal
- Utsab Khakurel
- Devendra Shah
- Saurav Keshari Aryal


**Overview:**

Implementing the following flavors of trees in C++ and realworld run-time analysis to insert and then delete all values from 1 to 1,000,000.

Implementing the following sorting Algorithms in C++ and realworld run-time analysis to sort values from 1,000,000 to 1 inserted in descending
order and sort them to ascending order.

Results for individual runs can be seen in the text files in the results sub-directory for each of the Trees and Sorts directories in the repository.



#Results over three experimental runs and average(in seconds):

**1 million insertions:**

* AVLTree -> (2.24652 + 1.96817 + 2.00946) / 3 = 2.07472 s
* 2-3 B Tree -> (0.594022 + 0.571282 + 0.544392) / 3 = 0.56990 s
* Red Black Tree -> (1.09105 + 0.943154 + 0.943515) / 3 = 0.99257 s
* Binary Search Tree -> (1.03495 + 0.893022 + 0.835576) / 3 = 0.92118 s

**1 million deletions:**

* AVLTree -> (0.312913 + 0.278984 + 0.287982) / 3 = 0.879879 s
* 2-3 B Tree -> (0.210755 + 0.193194 + 0.192079) / 3 = 0.198676 s
* Red Black Tree -> (0.247717 + 0.228094 + 0.226969) / 3 = 0.234260 s
* Binary Search Tree -> (0.187757 + 0.172333 + 0.175951) / 3 = 0.178680 s


**Sorting run-time for sorts**

* Selection Sort -> (2456.39 + 2465.98 + 2466.07) / 3 = 2462.81 s
* Quick Sort -> (0.130454 + 0.129811 + 0.133502) / 3 = 0.131256 s
* Merge Sort -> (0.60727 + 0.606253 + 0.607607) / 3 = 0.607043 s
* Radix Sort -> (0.153342 + 0.152003 + 0.15096) / 3 = 0.152102 s
* Heap Sort -> (1.05336 + 1.04988 + 1.05365) / 3 = 1.052297 s
* Bucket Sort -> (0.042082 + 0.042596 + 0.044476) / 3 = 0.043051 s
* Bubble Sort -> (9062.45 + 9100.24 + 9124.15) / 3 = 9095.61 s
* Insertion Sort -> (4163.77 + 4168.33 + 4157.74) / 3 = 4163.28 s



#Device Specifications

Trees were run and analysed using a Dell Inspiron 14 5000 with the following specifications:
- Intel i7 5th Gen Processor
- 8 GB DDR3 RAM
- g++ GNU compiler
- Ubuntu 14.04 Trusty LTS OS

Sorts were run and analysed using a MacBook Air (13-inch, Late 2010) with the following specifications:
- 1.86 GHz Intel Core 2 Duo
- 2 GB 1067 MHz DDR3
- g++ compiler
- OSX El Capitan Version 10.11.4 (15E65)