from matplotlib import pyplot as plt

EXACT_SOLUTION_URL = "./data/exactSolution.txt"
CG_SOLUTION_URL = "./data/cgSolution.txt"


def read_txt_file(file_url: str):
    with open(file_url, "r") as read_file:
        lines = read_file.readlines()
    return lines


def format_lines(lines):
    lines = [line.replace("\n", "") for line in lines]
    formatted_lines = [float(line.replace("\n", "")) for line in lines]
    return formatted_lines


def plot(*args):
    fig = plt.figure()
    for arg in args:
        plt.plot(arg)
    fig.savefig(f"./visualisation/figures/compare.png")


def main():
    ## Exact solution
    lines = read_txt_file(EXACT_SOLUTION_URL)
    formatted_lines_exact = format_lines(lines)

    ## Approximated solution
    lines = read_txt_file(CG_SOLUTION_URL)
    formatted_lines_cg = format_lines(lines)

    ## Plot
    plot(formatted_lines_exact, formatted_lines_cg)


if __name__ == "__main__":
    main()
