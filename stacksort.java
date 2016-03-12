public static void sort(Stack<Integer> s) {
    if (!s.isEmpty()) {
        Integer t = s.pop();
        sort(s);
        insert(t, s);
    }
}

private static void insert(Integer x, Stack<Integer> s) {
    if (s.isEmpty()) {
        s.push(x);
        return;
    }

    if (x < s.peek()) {
        Integer t = s.pop();
        insert(x, s);
        s.push(t);
    } else {
        s.push(x);
    }
}