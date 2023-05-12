fun main() {
    val (str1,str2) = readLine()!!.split(" ")

    var mn = 100

    for (i in 0..(str2.length - str1.length)) {
        var sum = 0
        for (j in 0..(str1.length-1)) {
            if (str1[j] != str2[j+i]) sum++
        }
        mn = if (mn > sum) sum else mn
    }

    println(mn)
}