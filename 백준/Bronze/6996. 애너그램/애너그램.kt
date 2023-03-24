import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val n : Int
    n = readLine()!!.toInt()
    val list = ArrayList<List<String>>()

    for (i in 1..n) {
        list.add(readLine()!!.split(' '))
    }

    for (element in list) {
        var result: Boolean = true;

        var alp1 = IntArray(26)
        var alp2 = IntArray(26)

        for (str in element.get(0)) {
            alp1[str - 'a']++
        }

        for (str in element.get(1)) {
            alp2[str - 'a']++
        }

        for(i in 0..25) {
            if (alp1[i] != alp2[i])
                result = false
        }

        if (result) {
            println("${element.get(0)} & ${element.get(1)} are anagrams.")
        } else {
            println("${element.get(0)} & ${element.get(1)} are NOT anagrams.")
        }
    }
}