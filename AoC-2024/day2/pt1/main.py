
def main():

    ans = 0

    try:
        while (user_input := input()):
            record = user_input.split()
            increasing = True
            decreasing = True
            # check increasing by 1 - 3;
            for i in range(1, len(record)):
                if record[i] < record[i - 1]:
                    increasing = False
                    break
                if abs(int(record[i]) - int(record[i - 1])) < 1 or abs(int(record[i]) - int(record[i - 1])) > 3:
                    increasing = False
                    break
            for i in range(1, len(record)):
                if record[i] > record[i - 1]:
                    decreasing = False
                    break
                if abs(int(record[i]) - int(record[i - 1])) < 1 or abs(int(record[i]) - int(record[i - 1])) > 3:
                    decreasing = False
                    break
            if increasing or decreasing:
                ans += 1
    except EOFError:
        pass

    print(ans)

if __name__ == "__main__":
    main()