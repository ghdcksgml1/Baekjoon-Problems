import java.lang.StringBuilder
import java.util.*

fun main() {
    val str1: String = readLine()!!.toString()
    val str2: String = readLine()!!.toString()


    val st1: Stack<Char> = Stack()
    val st2: Stack<Char> = Stack()

    for (i in (str1.length-1) downTo 0) {
        st2.push(str1[i])
    }

    while (!st2.isEmpty()) {
        val top = st2.pop()
        st1.push(top)
        var cnt = 1

        if (top == str2[0]) {
            for (i in 0..str2.length-2) {
                if (st2.empty()) break
                val ttop = st2.pop()
                st1.push(ttop)
                cnt ++

                if (ttop != str2[cnt-1]) {
                    for (j in 0..(cnt-2)) {
                        st2.push(st1.pop())
                    }
                    cnt = 0
                    break;
                }
            }
            if (cnt == str2.length) {
                for (i in 0..(cnt-1)) {
                    st1.pop()
                }

                for (i in 0..(str2.length-1)) {
                    if (!st1.empty()) {
                        st2.push(st1.pop())
                    }
                }
            }
        }
    }

    if (st1.isEmpty()) {
        println("FRULA")
        return
    }

    var str = StringBuilder()
    while (!st1.isEmpty()) {
        str.append(st1.pop())
    }

    println(str.reverse())
}