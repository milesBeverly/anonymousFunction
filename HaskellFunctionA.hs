module FunctionA where

import Control.Parallel (par, pseq)

functionA arr
    | length arr == 0 = 0
    | length arr == 1 = arr !! 0
    | otherwise = upper `par` (lower `pseq` (lower + upper))
        where
            lower = functionA (fst split)
            upper = functionA (snd split)
            split = splitAt (length arr `div` 2) arr