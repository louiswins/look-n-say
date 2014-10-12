namespace detail {
    // List types
    template <unsigned hd, class tl>
    struct cons {};
    struct nil {};

    // Calculate one iteration
    template <unsigned n, typename list> struct lns_one;
    template <unsigned n, unsigned cur, typename rest>
    struct lns_one<n, cons<cur, cons<cur, rest>>> {
        typedef typename lns_one<n+1, cons<cur, rest>>::t t;
    };
    template <unsigned n, unsigned cur, unsigned next, typename rest>
    struct lns_one<n, cons<cur, cons<next, rest>>> {
        typedef cons<n, cons<cur, typename lns_one<1, cons<next, rest>>::t>> t;
    };
    template <unsigned n, unsigned cur>
    struct lns_one<n, cons<cur, nil>> {
        typedef cons<n, cons<cur, nil>> t;
    };

    // Iterate
    template <unsigned iters, typename list>
    struct lns_multi {
        typedef typename lns_multi<iters-1, typename lns_one<1, list>::t>::t t;
    };
    template <typename list>
    struct lns_multi<0, list> {
        typedef list t;
    };
}

// Print a list
template <typename T>
struct printlist {
    template <typename stream>
    static void print(stream& s) {
        s << '\n';
    }
};
template <unsigned hd, typename tl>
struct printlist<detail::cons<hd, tl>> {
    template <typename stream>
    static void print(stream& s) {
        s << hd;
        printlist<tl>::print(s);
    }
};

// Calculate the look-and-say sequence
template <unsigned iters>
struct look_and_say {
    typedef typename detail::lns_multi<iters, detail::cons<1, detail::nil>>::t t;
};
