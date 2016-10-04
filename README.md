### Equity Options Pricing Model
---

#### Overview
---

This project contains two methods for calculating the value of equity options. One method is for American options, these allow owners to exercise the option at any time prior to its maturity date. The other method is for European options, which can only be exercised at maturity.

#### Requirements (Mac)
---

This project requires you to have the latest version of Xcode installed and the latest version of the Boost C++ libraries. Boost can be installed on your machine with Homebrew by entering `brew install --without-python boost` on the terminal. Follow this tutorial: `https://buddypanda.com/?p=10` to set up Boost within Xcode.

#### Installation (Mac)
---

1. Clone the repository by entering `git clone https://github.com/chrisdowd/options-pricing-model.git` in the command line.
2. Open `xCode`, select `File`, then `New Project`.
3. Under `OS X` click `create` and select `Command Line Tool Application`.
4. Name your project and then set its `type` to `C++`.
5. Include the files from either the American Option folder or European Option folder in your Xcode project folder.
6. Click `Run` to compile the program.
7. Enter option parameters in the output window to find option prices.
