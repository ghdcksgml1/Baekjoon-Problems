-- 코드를 입력하세요
SELECT M.MEMBER_ID, M.MEMBER_NAME, M.GENDER, date_format(M.DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE AS M
WHERE MONTH(M.DATE_OF_BIRTH) = '3'
AND M.GENDER = 'W'
AND M.TLNO <> 'NULL'
ORDER BY M.MEMBER_ID ASC;