# FianchettoAD

FianchettoAD is a programming language that supports automatic differentiation (autodiff) out of the box. With FianchettoAD, you can easily compute derivatives of functions without having to implement differentiation manually. 

## Features

- **Built-in Automatic Differentiation**: Calculate derivatives of functions effortlessly.
- **User-friendly Syntax**: Similar to C/C++, making it easy to learn and use.
- **Flexibility**: Supports multi-line comments and various data types.

## Example Code

Here is a simple example to demonstrate the usage of FianchettoAD:

```
differentiable double square(double x) {
  return x * x;
}

/*
  This is a multiline comment
*/

int main() {
  double y = square(5.0);
  double dydx = square'(5.0); // Derivative of square at x = 5.0
  return 0;
}
```

## Installation

FianchettoAD requires GNU Flex to be installed on your system. Below are the instructions for installing GNU Flex on different platforms:

### Ubuntu/Debian

```sh
sudo apt-get update
sudo apt-get install flex
```

### macOS

You can install GNU Flex using Homebrew:

```sh
brew install flex
```

### Windows

You can download the installer from the [Official Releases](https://github.com/westes/flex/releases) and follow the installation instructions.

## Building FianchettoAD

Once you have GNU Flex installed, you can build FianchettoAD by following these steps:

1. Create a build directory:

    ```sh
    mkdir build
    ```

2. Navigate to the build directory:

    ```sh
    cd build
    ```

3. Generate the build files using CMake:

    ```sh
    cmake -B ..
    ```

4. Build the project using `make`:

    ```sh
    make
    ```

## Usage

After building FianchettoAD, you can write your programs in `.fc` files and compile them using the FianchettoAD compiler.

## Contributing

We welcome contributions to FianchettoAD! If you have any bug reports, suggestions, or pull requests, please feel free to submit them on our GitHub repository.

## License

FianchettoAD is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or support, please reach out to me at [baxidhairya2312@gmail.com].

Happy Coding with FianchettoAD!