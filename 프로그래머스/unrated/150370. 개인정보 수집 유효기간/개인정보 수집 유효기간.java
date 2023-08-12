import java.util.*;

class Solution {

    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] answer = {};
        
        String[] todays = today.split("\\.");
        Tuple todayTuple = new Tuple(
                Integer.parseInt(todays[0]),
                Integer.parseInt(todays[1]),
                Integer.parseInt(todays[2]));
        List<Privacy> privacyList = new ArrayList<>();

        for (String privacy : privacies) {
            String[] privacySplit = privacy.split(" ");
            String[] date = privacySplit[0].split("\\.");
            String term = privacySplit[1];

            Privacy privacyInstance = new Privacy(
                    Integer.parseInt(date[0]),
                    Integer.parseInt(date[1]),
                    Integer.parseInt(date[2]),
                    term);

            privacyList.add(privacyInstance);
        }
        
        Map<String, Integer> termMap = new HashMap<>();
        
        for (String term : terms) {
            String[] s = term.split(" ");
            termMap.put(s[0], Integer.parseInt(s[1]));
        }

        int index = 1;
        List<Integer> answerList = new ArrayList<>();
        for (Privacy privacy : privacyList) {
            int year = todayTuple.a;
            int month = todayTuple.b;
            int day = todayTuple.c;
            Integer term = termMap.get(privacy.term);

            boolean trigger = false;

            // term 빼주는 연산
            while (term >= 12) {
                year -= 1;
                term -= 12;
            }
            
            if (term >= month) {
                year -= 1;
                month = 12 - (term-month);
            } else {
                month -= term;
            }
            
            System.out.println(year + " " + month + " " + day);
            
            // 비교하는 연산
            if (year > privacy.date) {
                trigger = true;
            } else if (year == privacy.date) {
                if (month > privacy.month) {
                    trigger = true;
                } else if (month == privacy.month) {
                    if (day >= privacy.day) {
                        trigger = true;
                    }
                }
            }
            


            if (trigger) {
                answerList.add(index);
                System.out.println(index);
            }
            index++;
        }
        
        answer = answerList.stream().mapToInt(Integer::intValue).toArray();

        return answer;
    }
    
    
}

class Pair {
    int a;
    int b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

class Tuple {
    int a;
    int b;
    int c;

    public Tuple(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class Privacy {
    int date;
    int month;
    int day;
    String term;

    public Privacy(int date, int month, int day, String term) {
        this.date = date;
        this.month = month;
        this.day = day;
        this.term = term;
    }
}